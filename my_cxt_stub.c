/* Stub for Perl_my_cxt_init - minimal implementation */
#include <windows.h>
#include <stdlib.h>

/* From perl.h / intrpvar.h - MY_CXT_INDEX type */
struct my_cxt_key {
    const char *name;
    int *indexp;
};

/* Simplified: just allocate and return */
void *
Perl_my_cxt_init(void *my_perl, int *indexp, size_t size)
{
    void *p = malloc(size);
    if (p) memset(p, 0, size);
    return p;
}
