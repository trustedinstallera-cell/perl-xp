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
