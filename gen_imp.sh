#!/bin/bash
cd /d/perl-xp/perl-5.40.3

{
echo '.section .rdata,"dr"'

# 从所有 .o 的 U 符号中，找 PL_ 和 Perl_ 和 win32_ 开头的
nm *.o 2>/dev/null | grep '^         U ' | sed 's/^         U _//' | grep '^PL_\|^Perl_\|^win32_' | sort -u | while read sym; do
    # 跳过已经在 perl_imp.o 里的
    case "$sym" in
        Perl_init_os_extras|Perl_win32_init|Perl_win32_term|win32_abort|win32_access|win32_alarm|win32_ansipath|win32_async_check|win32_calloc|win32_chdir|win32_chmod|win32_chsize|win32_clearenv|win32_clearerr|win32_close|win32_closedir|win32_crypt|win32_dup|win32_dup2|win32_environ|win32_errno|win32_execv|win32_execvp|win32_fclose|win32_fdopen|win32_feof|win32_ferror|win32_fflush|win32_fgetc|win32_fileno|win32_flock|win32_fopen|win32_fread|win32_free|win32_free_childdir|win32_free_childenv|win32_freopen|win32_fseek|win32_fstat|win32_ftell|win32_fwrite|win32_get_childdir|win32_get_childenv|win32_get_osfhandle|win32_getenv|win32_getpid|win32_gettimeofday|win32_ioctl|win32_isatty|win32_kill|win32_link|win32_lseek|win32_lstat|win32_malloc|win32_mkdir|win32_msgwait|win32_open|win32_open_osfhandle|win32_opendir|win32_pause|win32_pclose|win32_pipe|win32_popen|win32_popenlist|win32_putenv|win32_read|win32_readdir|win32_readlink|win32_realloc|win32_rename|win32_rewinddir|win32_rmdir|win32_seekdir|win32_setmode|win32_setvbuf|win32_signal|win32_sleep|win32_spawnvp|win32_stat|win32_stderr|win32_stdin|win32_stdout|win32_str_os_error|win32_strerror|win32_symlink|win32_tell|win32_telldir|win32_times|win32_tmpfd|win32_tmpfd_mode|win32_ungetc|win32_unlink|win32_utime|win32_vfprintf|win32_waitpid|win32_write)
            continue ;;
    esac
    echo ".globl __imp__${sym}"
    echo "__imp__${sym}:"
    echo "  .long _${sym}"
done
} > perl_imp2.S

echo "Generated perl_imp2.S"
wc -l perl_imp2.S
