/* Stubs for symbols that scope.o references but miniperl never calls */
#include "perl.h"

/* mro_isa_changed_in - never called in miniperl */
void Perl_mro_isa_changed_in(pTHX_ HV *stash) { PERL_UNUSED_ARG(stash); }

/* parser_free - never called in miniperl */
void Perl_parser_free(pTHX_ void *parser) { PERL_UNUSED_ARG(parser); }

/* mg_localize - never called in miniperl */
void Perl_mg_localize(pTHX_ SV *sv, SV *nsv, bool setmagic) {
    PERL_UNUSED_ARG(sv); PERL_UNUSED_ARG(nsv); PERL_UNUSED_ARG(setmagic);
}

/* save_scalar_at - never called in miniperl */
SV *Perl_save_scalar_at(pTHX_ SV **sptr, U32 flags) {
    PERL_UNUSED_ARG(sptr); PERL_UNUSED_ARG(flags);
    return NULL;
}

/* av_reify - never called in miniperl */
void Perl_av_reify(pTHX_ AV *av) { PERL_UNUSED_ARG(av); }

/* save_pushptri32ptr - never called in miniperl */
void Perl_save_pushptri32ptr(pTHX_ char *ptr1, I32 int2, void *ptr3, int type) {
    PERL_UNUSED_ARG(ptr1); PERL_UNUSED_ARG(int2); PERL_UNUSED_ARG(ptr3); PERL_UNUSED_ARG(type);
}

/* SAVEFEATUREBITS - macro that calls something, provide the underlying */
/* SAVEt_FEATUREBITS handling */
void Perl_save_pushi32ptr(pTHX_ const I32 i, void *const ptr, const int type) {
    PERL_UNUSED_ARG(i); PERL_UNUSED_ARG(ptr); PERL_UNUSED_ARG(type);
}
