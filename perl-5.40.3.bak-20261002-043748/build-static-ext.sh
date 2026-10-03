#!/bin/bash
set -e

PERL_DIR="/d/perl-xp/perl-5.40.3"
WIN32_DIR="$PERL_DIR/win32"
CORE_INC="-I$WIN32_DIR -I$PERL_DIR/lib/CORE"
XSUBPP="$PERL_DIR/lib/ExtUtils/xsubpp"
TYPEMAP="$PERL_DIR/lib/ExtUtils/typemap"

# 统一静态编译 flags —— 注意：没有 PERLDLL，没有 MULTIPLICITY，没有 PERL_IMPLICIT_SYS
STATIC_FLAGS="-DWIN32 -D_CONSOLE -DNO_STRICT -D_CRT_SECURE_NO_DEPRECATE \
  -DPERL_CORE -DPERL_STATIC_SYMS -DPERL_IMPLICIT_CONTEXT -DPERL_IMPLICIT_CONTEXT \
  -DUSE_SITECUSTOMIZE -DUSE_PERLIO -DUSE_HASH_SEED_EXPLICIT \
  -DWIN32_NO_RAW_EXCEPTIONS -march=pentium4 -std=c99 \
  -fwrapv -fno-strict-aliasing -mms-bitfields"

CC="gcc"
CFLAGS="$CORE_INC $STATIC_FLAGS"

echo "=== Step 1: Recompile Fcntl ==="
$CC $CFLAGS -c "$PERL_DIR/ext/Fcntl/Fcntl.c" -o "$PERL_DIR/ext/Fcntl/Fcntl.o"
echo "Fcntl.o done"

echo "=== Step 2: Recompile Cwd ==="
$CC $CFLAGS -c "$PERL_DIR/dist/PathTools/Cwd.c" -o "$PERL_DIR/dist/PathTools/Cwd.o"
echo "Cwd.o done"

echo "=== Step 3: Recompile POSIX ==="
$CC $CFLAGS -c "$PERL_DIR/ext/POSIX/POSIX.c" -o "$PERL_DIR/ext/POSIX/POSIX.o"
echo "POSIX.o done"

echo "=== Step 4: Compile IO ==="
$CC $CFLAGS -c "$PERL_DIR/dist/IO/IO.c" -o "$PERL_DIR/dist/IO/IO.o"
echo "IO.o done"

echo "=== Step 5: Compile poll.c (IO dependency) ==="
if [ -f "$PERL_DIR/dist/IO/poll.c" ]; then
    $CC $CFLAGS -c "$PERL_DIR/dist/IO/poll.c" -o "$PERL_DIR/dist/IO/poll.o"
    echo "poll.o done"
fi

echo "=== Step 6: Compile Socket ==="
$CC $CFLAGS -c "$PERL_DIR/cpan/Socket/Socket.c" -o "$PERL_DIR/cpan/Socket/Socket.o"
echo "Socket.o done"

echo "=== Step 7: Verify no __imp__ stubs ==="
FAIL=0
for o in \
  "$PERL_DIR/ext/Fcntl/Fcntl.o" \
  "$PERL_DIR/dist/PathTools/Cwd.o" \
  "$PERL_DIR/ext/POSIX/POSIX.o" \
  "$PERL_DIR/dist/IO/IO.o" \
  "$PERL_DIR/dist/IO/poll.o" \
  "$PERL_DIR/cpan/Socket/Socket.o"; do
    if [ -f "$o" ]; then
        IMP_COUNT=$(nm "$o" 2>/dev/null | grep '__imp__' | wc -l)
        printf "  %-30s __imp__ count = %d\n" "$(basename $(dirname $o))/$(basename $o)" "$IMP_COUNT"
        if [ "$IMP_COUNT" -gt 0 ]; then
            FAIL=1
        fi
    fi
done

if [ $FAIL -eq 1 ]; then
    echo "*** WARNING: Some .o files still have __imp__ stubs! ***"
    echo "*** Check that -DPERL_STATIC_SYMS -DPERL_IMPLICIT_CONTEXT -DPERL_IMPLICIT_CONTEXT is in CFLAGS ***"
fi

echo "=== Step 8: Copy .o files to win32/ ==="
cp "$PERL_DIR/ext/Fcntl/Fcntl.o" "$WIN32_DIR/"
cp "$PERL_DIR/dist/PathTools/Cwd.o" "$WIN32_DIR/"
cp "$PERL_DIR/ext/POSIX/POSIX.o" "$WIN32_DIR/"
cp "$PERL_DIR/dist/IO/IO.o" "$WIN32_DIR/"
[ -f "$PERL_DIR/dist/IO/poll.o" ] && cp "$PERL_DIR/dist/IO/poll.o" "$WIN32_DIR/"
cp "$PERL_DIR/cpan/Socket/Socket.o" "$WIN32_DIR/"
echo "Copied all .o to win32/"

echo "=== Step 9: Update xs_init.c ==="
cat > "$WIN32_DIR/xs_init.c" << 'XS_EOF'
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

/* boot functions for statically linked XS modules */
EXTERN_C void boot_DynaLoader(pTHX_ CV* cv);
EXTERN_C void boot_IO(pTHX_ CV* cv);
EXTERN_C void boot_Cwd(pTHX_ CV* cv);
EXTERN_C void boot_Fcntl(pTHX_ CV* cv);
EXTERN_C void boot_POSIX(pTHX_ CV* cv);
EXTERN_C void boot_Socket(pTHX_ CV* cv);

EXTERN_C void
xs_init(pTHX)
{
    static const char file[] = __FILE__;

    newXS("DynaLoader::boot_DynaLoader", boot_DynaLoader, file);
    newXS("IO::bootstrap", boot_IO, file);
    newXS("Cwd::bootstrap", boot_Cwd, file);
    newXS("Fcntl::bootstrap", boot_Fcntl, file);
    newXS("POSIX::bootstrap", boot_POSIX, file);
    newXS("Socket::bootstrap", boot_Socket, file);
}
XS_EOF

$CC $CFLAGS -c "$WIN32_DIR/xs_init.c" -o "$WIN32_DIR/xs_init.o"
echo "xs_init.o done"

echo "=== Step 10: Update staticlinkmodules.c ==="
cat > "$WIN32_DIR/staticlinkmodules.c" << 'STATIC_EOF'
#include <stddef.h>

char *staticlinkmodules[] = {
    "DynaLoader",
    "IO",
    "Cwd",
    "Fcntl",
    "POSIX",
    "Socket",
    NULL
};
STATIC_EOF

$CC $CFLAGS -c "$WIN32_DIR/staticlinkmodules.c" -o "$WIN32_DIR/staticlinkmodules.o"
echo "staticlinkmodules.o done"

echo "=== Step 11: Relink perl.exe ==="
cd "$WIN32_DIR"

g++ -o perl.exe *.o \
  -lkernel32 -luser32 -lgdi32 -lws2_32 -lcomdlg32 -ladvapi32 \
  -lshell32 -lole32 -loleaut32 -luuid -lm -lcomctl32 \
  -mconsole 2>&1

echo "=== DONE ==="
ls -la perl.exe
echo "Testing..."
./perl.exe -v
