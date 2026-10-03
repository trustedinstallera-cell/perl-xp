Perl 5.40.3 Static Build for Windows XP (32-bit)
================================================

This is a statically-linked build of Perl 5.40.3 targeting Windows XP
(32-bit, x86), built with MinGW-w64 GCC 11.1.0.

  Version:     Perl v5.40.3 (2025)
  Platform:    MSWin32-x86-multi-thread
  Threading:   MULTIPLICITY + USE_ITHREADS
  Link model:  Static (no VC++ runtime, no MinGW DLL dependency)
  Build tool:  gcc 11.1.0 (i686-w64-mingw32)

Contents
--------
  bin\perl.exe        Perl interpreter (~1.5 MB)
  bin\perl540.dll     Core runtime library (2.5 MB)
  lib\                Core Perl modules (.pm files)
  README.txt          This file

Installation
------------
1. Extract this archive to any directory, e.g.:
     C:\perl-5.40.3\

2. Add the bin\ directory to your PATH:
     set PATH=C:\perl-5.40.3\bin;%PATH%

3. Verify:
     perl -v

Built-in XS Modules
-------------------
The following XS modules are statically linked into perl540.dll
and require no external .dll files:

  POSIX      Fcntl      Win32      DynaLoader      Win32CORE

Usage Notes
-----------
- Tested on Windows XP SP3 (32-bit). Should work on XP RTM with
  winhttp.dll from SP1+ placed in bin\ (see below).
- Pure-Perl CPAN modules install and work normally.
- XS module compilation requires the full build environment
  (headers in lib\CORE\, import library libperl540.a).
- On Windows XP RTM (no Service Pack), winhttp.dll is absent.
  Copy winhttp.dll from an XP SP3 or Server 2003 machine into
  bin\ to resolve this. No other DLL dependencies are missing.
- cmd.exe does not support single quotes in -e. Use double quotes:
    perl -e "print 'hello\n';"

License
-------
Perl 5 is distributed under the GNU General Public License or the
Artistic License. See https://www.perl.org/ for details.

Built by the Perl XP Static Build project, 2026.
