/* dirent.h - provides perl's DIR and struct direct, delegates struct dirent to system */

/* First get system dirent.h for struct dirent definition */
/* But we need to avoid DIR conflict since perl defines its own */
#define DIR __system_DIR
#include <../i686-w64-mingw32/include/dirent.h>
#undef DIR

/* Now define perl's own DIR type (struct _dir_struc) */
#ifndef _INC_DIRENT
#define _INC_DIRENT

/* Directory entry size */
#ifdef DIRSIZ
#undef DIRSIZ
#endif
#define DIRSIZ(rp)  (sizeof(struct direct))

/* structure of a directory entry (MS-DOS compat) */
struct direct
{
    long    d_ino;
    long    d_namlen;
    char    d_name[257];
};

/* structure for dir operations - perl's own DIR */
typedef struct _dir_struc
{
    char    *start;
    char    *curr;
    long    size;
    long    nfiles;
    struct direct dirstr;
    void*   handle;
    char    *end;
} DIR;

#endif /* _INC_DIRENT */
