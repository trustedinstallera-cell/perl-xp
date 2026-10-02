#!/bin/sh

set -e

CC="C:/toolchains/gcc-win98/bin/gcc"
CXX="C:/toolchains/gcc-win98/bin/g++.exe"
INCLUDE_WIN32="win32/include"

CFLAGS="-I. -Iwin32 -DPERL_CORE -DPERL_EXT_RE_BUILD -D_WIN32_WINNT=0x0501 -Wno-error -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast -O0 -g -DWIN32 -DPERL_TEXTMODE_SCRIPTS -DUSE_PERLIO -D__USE_MINGW_ANSI_STDIO -fwrapv -fno-strict-aliasing -mms-bitfields"

echo "=== Step 0: Generate perlmain.c ==="
if [ ! -f perlmain.c ]; then
    sed 's/#define PERL_IN_MINIPERLMAIN_C/#define PERL_IN_PERLMAIN_C/' miniperlmain.c > perlmain.c
    echo "  Generated perlmain.c"
else
    echo "  SKIP perlmain.c (already exists)"
fi

echo "=== Step 1: Compile core .c files ==="

for src in \
    av.c builtin.c caretx.c class.c deb.c doio.c doop.c dquote.c dump.c \
    globals.c globals_static.c gv.c hv.c keywords.c locale.c mathoms.c mg.c \
    mro_core.c numeric.c op.c pad.c peep.c perlio.c perly.c pp.c pp_ctl.c \
    pp_hot.c pp_pack.c pp_sort.c pp_sys.c reentr.c regcomp.c regcomp_debug.c \
    regcomp_invlist.c regcomp_study.c regcomp_trie.c regexec.c run.c scope.c \
    sv.c taint.c time64.c toke.c universal.c utf8.c util.c vutil.c
do
    obj=$(echo "$src" | sed 's/\.c$/.o/')
    if [ -f "$obj" ]; then
        echo "  SKIP $src"
    else
        echo "  CC $src"
        "$CC" -c $CFLAGS -o "$obj" "$src"
    fi
done

echo "=== Step 2: Compile perlmain.c and miniperlmain.c ==="

if [ ! -f perlmain.o ]; then
    echo "  CC perlmain.c"
    "$CC" -c $CFLAGS -o perlmain.o perlmain.c
else
    echo "  SKIP perlmain.c"
fi

if [ ! -f miniperlmain.o ]; then
    echo "  CC miniperlmain.c"
    "$CC" -c $CFLAGS -DPERL_IN_MINIPERLMAIN_C -o miniperlmain.o miniperlmain.c
else
    echo "  SKIP miniperlmain.c"
fi

echo "=== Step 3: Compile DynaLoader.c ==="

if [ ! -f DynaLoader.o ]; then
    echo "  CC ext/DynaLoader/DynaLoader.c -> DynaLoader.o"
    "$CC" -c $CFLAGS -I. -Iwin32 -Iwin32/include -o DynaLoader.o ext/DynaLoader/DynaLoader.c
else
    echo "  SKIP DynaLoader.c"
fi

echo "=== Step 4: Compile win32/ files ==="

cd win32
for src in win32.c win32thread.c win32sck.c fcrypt.c perllib.c xs_init.c staticlinkmodules.c; do
    obj=$(echo "$src" | sed 's/\.c$/.o/')
    if [ -f "$obj" ]; then
        echo "  SKIP $src"
    else
        echo "  CC $src"
        "$CC" -c $CFLAGS -I.. -I../$INCLUDE_WIN32 -o "$obj" "$src"
    fi
done
cd ..

echo "=== Step 5: Link perl.exe ==="

"$CXX" -mconsole -o perl.exe \
    perlmain.o \
    av.o builtin.o caretx.o class.o deb.o doio.o doop.o dquote.o dump.o \
   globals_static.o gv.o hv.o keywords.o locale.o mathoms.o mg.o \
    mro_core.o numeric.o op.o pad.o peep.o perlio.o perly.o pp.o pp_ctl.o \
    pp_hot.o pp_pack.o pp_sort.o pp_sys.o reentr.o regcomp.o regcomp_debug.o \
    regcomp_invlist.o regcomp_study.o regcomp_trie.o regexec.o run.o scope.o \
    sv.o taint.o time64.o toke.o universal.o utf8.o util.o\
    DynaLoader.o \
    win32/win32.o win32/win32thread.owin32/fcrypt.o win32/perllib.o win32/xs_init.o win32/staticlinkmodules.o \
    win32/Win32CORE.o \
    -lmoldname -lkernel32 -luser32 -lgdi32 -lwinspool -lcomdlg32 \
    -ladvapi32 -lshell32 -lole32 -loleaut32 -lnetapi32 -luuid \
    -lws2_32 -lmpr -lwinmm -lversion -lodbc32 -lodbccp32 -lcomctl32

echo "=== DONE ==="
ls -la perl.exe
echo ""
echo "Testing..."
./perl.exe -v

