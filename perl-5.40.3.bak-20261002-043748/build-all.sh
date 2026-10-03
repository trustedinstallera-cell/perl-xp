#!/bin/bash
set -e

PERL_DIR="/d/perl-xp/perl-5.40.3"
WIN32_DIR="$PERL_DIR/win32"
CORE_INC="-I$WIN32_DIR -I$PERL_DIR/lib/CORE"
MINIPERL="$PERL_DIR/miniperl.exe"

# 静态编译 flags
STATIC_FLAGS="-DWIN32 -D_CONSOLE -DNO_STRICT -D_CRT_SECURE_NO_DEPRECATE \
  -DPERL_CORE -DPERL_STATIC_SYMS \
  -DUSE_SITECUSTOMIZE -DUSE_PERLIO -DUSE_HASH_SEED_EXPLICIT \
  -DWIN32_NO_RAW_EXCEPTIONS -march=pentium4 -std=c99 \
  -fwrapv -fno-strict-aliasing -mms-bitfields"

CC="gcc"
CFLAGS="$CORE_INC $STATIC_FLAGS"

echo "========================================="
echo "=== Step 0: Check config.h ==="
echo "========================================="
grep 'define USE_ITHREADS' "$PERL_DIR/lib/CORE/config.h" && echo "*** WARNING: USE_ITHREADS still defined ***" || echo "USE_ITHREADS: OK (undefined)"
grep 'define MULTIPLICITY' "$PERL_DIR/lib/CORE/config.h" && echo "*** WARNING: MULTIPLICITY still defined ***" || echo "MULTIPLICITY: OK (undefined)"
grep 'define PERL_IMPLICIT_SYS' "$PERL_DIR/lib/CORE/config.h" && echo "*** WARNING: PERL_IMPLICIT_SYS still defined ***" || echo "PERL_IMPLICIT_SYS: OK (undefined)"

echo ""
echo "========================================="
echo "=== Step 1: Compile core .c files ==="
echo "========================================="

# 核心 .c 文件列表（排除 malloc.c 和 vutil.c 暂用系统版本）
CORE_C_FILES="av.c builtin.c caretx.c class.c deb.c doio.c doop.c dquote.c dump.c gv.c hv.c keywords.c locale.c mathoms.c mg.c mro_core.c numeric.c op.c pad.c perl.c perly.c pp.c pp_ctl.c pp_hot.c pp_pack.c pp_sort.c pp_sys.c reentr.c regcomp.c regcomp_trie.c regexec.c run.c scope.c sv.c taint.c toke.c universal.c utf8.c util.c"

cd "$PERL_DIR"
for cfile in $CORE_C_FILES; do
    if [ -f "$cfile" ]; then
        echo "  Compiling $cfile ..."
        $CC $CFLAGS -c "$cfile" -o "${cfile%.c}.o"
    else
        echo "  SKIP $cfile (not found)"
    fi
done

echo "Core .o files done"
ls -la *.o | wc -l

echo ""
echo "========================================="
echo "=== Step 2: Compile win32/*.c ==="
echo "========================================="

# win32 目录下的文件
cd "$WIN32_DIR"
WIN32_C_FILES="win32.c perllib.c DynaLoader.c Win32CORE.c"

for cfile in $WIN32_C_FILES; do
    if [ -f "$cfile" ]; then
        echo "  Compiling win32/$cfile ..."
        $CC $CFLAGS -c "$cfile" -o "${cfile%.c}.o"
    else
        echo "  SKIP win32/$cfile (not found)"
    fi
done

# 额外 win32 下的其他 .c
for cfile in "$WIN32_DIR"/*.c; do
    base=$(basename "$cfile")
    case "$base" in
        win32.c|perllib.c|DynaLoader.c|Win32CORE.c) ;;
        *)
            echo "  Compiling win32/$base ..."
            $CC $CFLAGS -c "$cfile" -o "${cfile%.c}.o"
            ;;
    esac
done

echo "win32 .o files done"

echo ""
echo "========================================="
echo "=== Step 3: Regenerate & compile XS extensions ==="
echo "========================================="

# 函数：重新生成并编译一个扩展
build_ext() {
    local ext_dir="$1"
    local xs_file="$2"
    local c_file="$3"
    local o_file="$4"
    
    echo "--- Building $ext_dir ---"
    cd "$PERL_DIR/$ext_dir"
    
    # 重新生成 const 文件（如果需要）
    if grep -q 'ExtUtils::Constant' "$xs_file" 2>/dev/null; then
        if [ ! -f const-c.inc ]; then
            rm -f const-c.inc const-xs.inc
            "$MINIPERL" -I"$PERL_DIR/lib" Makefile.PL INSTALLDIRS=perl PERL_CORE=1 2>/dev/null || true
        fi
        echo "  const files: $(ls -l const-c.inc const-xs.inc 2>&1 | wc -l) files present"
    fi
    
    # 生成 .c
    rm -f "$c_file"
    "$MINIPERL" -I"$PERL_DIR/lib" "$PERL_DIR/lib/ExtUtils/xsubpp" \
        -typemap "$PERL_DIR/lib/ExtUtils/typemap" "$xs_file" > "$c_file"
    
    # 编译
    $CC $CFLAGS -c "$c_file" -o "$o_file"
    echo "  $o_file done"
}

build_ext "ext/Fcntl" "Fcntl.xs" "Fcntl.c" "Fcntl.o"
build_ext "dist/PathTools" "Cwd.xs" "Cwd.c" "Cwd.o"
build_ext "ext/POSIX" "POSIX.xs" "POSIX.c" "POSIX.o"
build_ext "dist/IO" "IO.xs" "IO.c" "IO.o"
build_ext "cpan/Socket" "Socket.xs" "Socket.c" "Socket.o"

# IO 还需要 poll.c
if [ -f "$PERL_DIR/dist/IO/poll.c" ]; then
    cd "$PERL_DIR/dist/IO"
    $CC $CFLAGS -c poll.c -o poll.o
    echo "poll.o done"
fi

echo ""
echo "========================================="
echo "=== Step 4: Copy .o files to win32/ ==="
echo "========================================="

cp "$PERL_DIR/ext/Fcntl/Fcntl.o" "$WIN32_DIR/"
cp "$PERL_DIR/dist/PathTools/Cwd.o" "$WIN32_DIR/"
cp "$PERL_DIR/ext/POSIX/POSIX.o" "$WIN32_DIR/"
cp "$PERL_DIR/dist/IO/IO.o" "$WIN32_DIR/"
[ -f "$PERL_DIR/dist/IO/poll.o" ] && cp "$PERL_DIR/dist/IO/poll.o" "$WIN32_DIR/"
cp "$PERL_DIR/cpan/Socket/Socket.o" "$WIN32_DIR/"

echo "Copied."

echo ""
echo "========================================="
echo "=== Step 5: xs_init.c + staticlinkmodules.c ==="
echo "========================================="

cat > "$WIN32_DIR/xs_init.c" << 'XS_EOF'
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

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

echo "xs_init.o and staticlinkmodules.o done"

echo ""
echo "========================================="
echo "=== Step 6: Link perl.exe ==="
echo "========================================="

cd "$WIN32_DIR"

# 显式列出需要的 .o，排除 perlglob.o 和 runperl.o
g++ -o perl.exe \
    perllib.o win32.o win32sck.o win32thread.o \
    DynaLoader.o Win32CORE.o \
    xs_init.o staticlinkmodules.o \
    Fcntl.o Cwd.o POSIX.o IO.o poll.o Socket.o \
    av.o builtin.o caretx.o class.o deb.o doio.o doop.o \
    dquote.o dump.o gv.o hv.o keywords.o locale.o mathoms.o \
    mg.o mro_core.o numeric.o op.o pad.o perl.o perly.o \
    pp.o pp_ctl.o pp_hot.o pp_pack.o pp_sort.o pp_sys.o \
    reentr.o regcomp.o regcomp_trie.o regexec.o run.o \
    scope.o sv.o taint.o toke.o universal.o utf8.o util.o \
    -lkernel32 -luser32 -lgdi32 -lws2_32 -lcomdlg32 -ladvapi32 \
    -lshell32 -lole32 -loleaut32 -luuid -lm -lcomctl32 \
    -mconsole 2>&1
echo ""
echo "========================================="
echo "=== DONE ==="
echo "========================================="
ls -la perl.exe
echo "Testing..."
./perl.exe -v
