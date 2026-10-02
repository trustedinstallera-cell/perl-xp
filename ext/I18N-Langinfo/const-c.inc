#define PERL_constant_NOTFOUND	1
#define PERL_constant_NOTDEF	2
#define PERL_constant_ISIV	3
#define PERL_constant_ISNO	4
#define PERL_constant_ISNV	5
#define PERL_constant_ISPV	6
#define PERL_constant_ISPVN	7
#define PERL_constant_ISSV	8
#define PERL_constant_ISUNDEF	9
#define PERL_constant_ISUV	10
#define PERL_constant_ISYES	11

#ifndef NVTYPE
typedef double NV; /* 5.6 and later define NVTYPE, and typedef NV to it.  */
#endif
#ifndef aTHX_
#define aTHX_ /* 5.6 or later define this for threading support.  */
#endif
#ifndef pTHX_
#define pTHX_ /* 5.6 or later define this for threading support.  */
#endif

/* This allows slightly more efficient code on !USE_ITHREADS: */
#ifdef USE_ITHREADS
#  define COP_FILE(c)	CopFILE(c)
#  define COP_FILE_F	"s"
#else
#  define COP_FILE(c)	CopFILESV(c)
#  define COP_FILE_F	SVf
#endif

static void
constant_add_symbol(pTHX_  HV *hash, const char *name, I32 namelen, SV *value) {
    HE *he = (HE*) hv_common_key_len(hash, name, namelen, HV_FETCH_LVALUE, NULL,
				     0);
    SV *sv;

    if (!he) {
        croak("Couldn't add key '%s' to %%I18N::Langinfo::",
		   name);
    }
    sv = HeVAL(he);
    if (SvOK(sv) || SvTYPE(sv) == SVt_PVGV) {
	/* Someone has been here before us - have to make a real sub.  */
	newCONSTSUB(hash, name, value);
    } else {
	SvUPGRADE(sv, SVt_RV);
	SvRV_set(sv, value);
	SvROK_on(sv);
	SvREADONLY_on(value);
    }
}



#ifndef SYMBIAN

/* Store a hash of all symbols missing from the package. To avoid trampling on
   the package namespace (uninvited) put each package's hash in our namespace.
   To avoid creating lots of typeblogs and symbol tables for sub-packages, put
   each package's hash into one hash in our namespace.  */

static HV *
get_missing_hash(pTHX) {
    HV *const parent
	= get_hv("ExtUtils::Constant::ProxySubs::Missing", GVf_MULTI);
    /* We could make a hash of hashes directly, but this would confuse anything
	at Perl space that looks at us, and as we're visible in Perl space,
	best to play nice. */
    SV *const *const ref
	= hv_fetch(parent, "I18N::Langinfo", 14, TRUE);
    HV *new_hv;

    if (!ref)
	return NULL;

    if (SvROK(*ref))
	return (HV*) SvRV(*ref);

    new_hv = newHV();
    SvUPGRADE(*ref, SVt_RV);
    SvRV_set(*ref, (SV *)new_hv);
    SvROK_on(*ref);
    return new_hv;
}

#endif

struct notfound_s {const char *name; I32 namelen;} ;

    static const struct notfound_s values_for_notfound[] =
      {
#ifndef CODESET
        { "CODESET", 7 },
#endif
#if defined(ABDAY_1) || (defined(_NL_ITEM))
#else
        { "ABDAY_1", 7 },
#endif
#if defined(ABDAY_2) || (defined(_NL_ITEM))
#else
        { "ABDAY_2", 7 },
#endif
#if defined(ABDAY_3) || (defined(_NL_ITEM))
#else
        { "ABDAY_3", 7 },
#endif
#if defined(ABDAY_4) || (defined(_NL_ITEM))
#else
        { "ABDAY_4", 7 },
#endif
#if defined(ABDAY_5) || (defined(_NL_ITEM))
#else
        { "ABDAY_5", 7 },
#endif
#if defined(ABDAY_6) || (defined(_NL_ITEM))
#else
        { "ABDAY_6", 7 },
#endif
#if defined(ABDAY_7) || (defined(_NL_ITEM))
#else
        { "ABDAY_7", 7 },
#endif
#if defined(ABMON_1) || (defined(_NL_ITEM))
#else
        { "ABMON_1", 7 },
#endif
#if defined(ABMON_10) || (defined(_NL_ITEM))
#else
        { "ABMON_10", 8 },
#endif
#if defined(ABMON_11) || (defined(_NL_ITEM))
#else
        { "ABMON_11", 8 },
#endif
#if defined(ABMON_12) || (defined(_NL_ITEM))
#else
        { "ABMON_12", 8 },
#endif
#if defined(ABMON_2) || (defined(_NL_ITEM))
#else
        { "ABMON_2", 7 },
#endif
#if defined(ABMON_3) || (defined(_NL_ITEM))
#else
        { "ABMON_3", 7 },
#endif
#if defined(ABMON_4) || (defined(_NL_ITEM))
#else
        { "ABMON_4", 7 },
#endif
#if defined(ABMON_5) || (defined(_NL_ITEM))
#else
        { "ABMON_5", 7 },
#endif
#if defined(ABMON_6) || (defined(_NL_ITEM))
#else
        { "ABMON_6", 7 },
#endif
#if defined(ABMON_7) || (defined(_NL_ITEM))
#else
        { "ABMON_7", 7 },
#endif
#if defined(ABMON_8) || (defined(_NL_ITEM))
#else
        { "ABMON_8", 7 },
#endif
#if defined(ABMON_9) || (defined(_NL_ITEM))
#else
        { "ABMON_9", 7 },
#endif
#if defined(ALT_DIGITS) || (defined(_NL_ITEM))
#else
        { "ALT_DIGITS", 10 },
#endif
#if defined(AM_STR) || (defined(_NL_ITEM))
#else
        { "AM_STR", 6 },
#endif
#if defined(DAY_1) || (defined(_NL_ITEM))
#else
        { "DAY_1", 5 },
#endif
#if defined(DAY_2) || (defined(_NL_ITEM))
#else
        { "DAY_2", 5 },
#endif
#if defined(DAY_3) || (defined(_NL_ITEM))
#else
        { "DAY_3", 5 },
#endif
#if defined(DAY_4) || (defined(_NL_ITEM))
#else
        { "DAY_4", 5 },
#endif
#if defined(DAY_5) || (defined(_NL_ITEM))
#else
        { "DAY_5", 5 },
#endif
#if defined(DAY_6) || (defined(_NL_ITEM))
#else
        { "DAY_6", 5 },
#endif
#if defined(DAY_7) || (defined(_NL_ITEM))
#else
        { "DAY_7", 5 },
#endif
#if defined(D_FMT) || (defined(_NL_ITEM))
#else
        { "D_FMT", 5 },
#endif
#if defined(D_T_FMT) || (defined(_NL_ITEM))
#else
        { "D_T_FMT", 7 },
#endif
#if defined(ERA) || (defined(_NL_ITEM))
#else
        { "ERA", 3 },
#endif
#if defined(ERA_D_FMT) || (defined(_NL_ITEM))
#else
        { "ERA_D_FMT", 9 },
#endif
#if defined(ERA_D_T_FMT) || (defined(_NL_ITEM))
#else
        { "ERA_D_T_FMT", 11 },
#endif
#if defined(ERA_T_FMT) || (defined(_NL_ITEM))
#else
        { "ERA_T_FMT", 9 },
#endif
#if defined(MON_1) || (defined(_NL_ITEM))
#else
        { "MON_1", 5 },
#endif
#if defined(MON_10) || (defined(_NL_ITEM))
#else
        { "MON_10", 6 },
#endif
#if defined(MON_11) || (defined(_NL_ITEM))
#else
        { "MON_11", 6 },
#endif
#if defined(MON_12) || (defined(_NL_ITEM))
#else
        { "MON_12", 6 },
#endif
#if defined(MON_2) || (defined(_NL_ITEM))
#else
        { "MON_2", 5 },
#endif
#if defined(MON_3) || (defined(_NL_ITEM))
#else
        { "MON_3", 5 },
#endif
#if defined(MON_4) || (defined(_NL_ITEM))
#else
        { "MON_4", 5 },
#endif
#if defined(MON_5) || (defined(_NL_ITEM))
#else
        { "MON_5", 5 },
#endif
#if defined(MON_6) || (defined(_NL_ITEM))
#else
        { "MON_6", 5 },
#endif
#if defined(MON_7) || (defined(_NL_ITEM))
#else
        { "MON_7", 5 },
#endif
#if defined(MON_8) || (defined(_NL_ITEM))
#else
        { "MON_8", 5 },
#endif
#if defined(MON_9) || (defined(_NL_ITEM))
#else
        { "MON_9", 5 },
#endif
#if defined(NOEXPR) || (defined(_NL_ITEM))
#else
        { "NOEXPR", 6 },
#endif
#if defined(NOSTR) || (defined(_NL_ITEM))
#else
        { "NOSTR", 5 },
#endif
#if defined(PM_STR) || (defined(_NL_ITEM))
#else
        { "PM_STR", 6 },
#endif
#if defined(T_FMT) || (defined(_NL_ITEM))
#else
        { "T_FMT", 5 },
#endif
#if defined(T_FMT_AMPM) || (defined(_NL_ITEM))
#else
        { "T_FMT_AMPM", 10 },
#endif
#if defined(YESEXPR) || (defined(_NL_ITEM))
#else
        { "YESEXPR", 7 },
#endif
#if defined(YESSTR) || (defined(_NL_ITEM))
#else
        { "YESSTR", 6 },
#endif
#if defined(_NL_ADDRESS_POSTAL_FMT) || (defined(_NL_ITEM))
#else
        { "_NL_ADDRESS_POSTAL_FMT", 22 },
#endif
#if defined(_NL_ADDRESS_COUNTRY_NAME) || (defined(_NL_ITEM))
#else
        { "_NL_ADDRESS_COUNTRY_NAME", 24 },
#endif
#if defined(_NL_ADDRESS_COUNTRY_POST) || (defined(_NL_ITEM))
#else
        { "_NL_ADDRESS_COUNTRY_POST", 24 },
#endif
#if defined(_NL_ADDRESS_COUNTRY_AB2) || (defined(_NL_ITEM))
#else
        { "_NL_ADDRESS_COUNTRY_AB2", 23 },
#endif
#if defined(_NL_ADDRESS_COUNTRY_AB3) || (defined(_NL_ITEM))
#else
        { "_NL_ADDRESS_COUNTRY_AB3", 23 },
#endif
#if defined(_NL_ADDRESS_COUNTRY_CAR) || (defined(_NL_ITEM))
#else
        { "_NL_ADDRESS_COUNTRY_CAR", 23 },
#endif
#if defined(_NL_ADDRESS_COUNTRY_NUM) || (defined(_NL_ITEM))
#else
        { "_NL_ADDRESS_COUNTRY_NUM", 23 },
#endif
#if defined(_NL_ADDRESS_COUNTRY_ISBN) || (defined(_NL_ITEM))
#else
        { "_NL_ADDRESS_COUNTRY_ISBN", 24 },
#endif
#if defined(_NL_ADDRESS_LANG_NAME) || (defined(_NL_ITEM))
#else
        { "_NL_ADDRESS_LANG_NAME", 21 },
#endif
#if defined(_NL_ADDRESS_LANG_AB) || (defined(_NL_ITEM))
#else
        { "_NL_ADDRESS_LANG_AB", 19 },
#endif
#if defined(_NL_ADDRESS_LANG_TERM) || (defined(_NL_ITEM))
#else
        { "_NL_ADDRESS_LANG_TERM", 21 },
#endif
#if defined(_NL_ADDRESS_LANG_LIB) || (defined(_NL_ITEM))
#else
        { "_NL_ADDRESS_LANG_LIB", 20 },
#endif
#if defined(_NL_IDENTIFICATION_TITLE) || (defined(_NL_ITEM))
#else
        { "_NL_IDENTIFICATION_TITLE", 24 },
#endif
#if defined(_NL_IDENTIFICATION_SOURCE) || (defined(_NL_ITEM))
#else
        { "_NL_IDENTIFICATION_SOURCE", 25 },
#endif
#if defined(_NL_IDENTIFICATION_ADDRESS) || (defined(_NL_ITEM))
#else
        { "_NL_IDENTIFICATION_ADDRESS", 26 },
#endif
#if defined(_NL_IDENTIFICATION_CONTACT) || (defined(_NL_ITEM))
#else
        { "_NL_IDENTIFICATION_CONTACT", 26 },
#endif
#if defined(_NL_IDENTIFICATION_EMAIL) || (defined(_NL_ITEM))
#else
        { "_NL_IDENTIFICATION_EMAIL", 24 },
#endif
#if defined(_NL_IDENTIFICATION_TEL) || (defined(_NL_ITEM))
#else
        { "_NL_IDENTIFICATION_TEL", 22 },
#endif
#if defined(_NL_IDENTIFICATION_FAX) || (defined(_NL_ITEM))
#else
        { "_NL_IDENTIFICATION_FAX", 22 },
#endif
#if defined(_NL_IDENTIFICATION_LANGUAGE) || (defined(_NL_ITEM))
#else
        { "_NL_IDENTIFICATION_LANGUAGE", 27 },
#endif
#if defined(_NL_IDENTIFICATION_TERRITORY) || (defined(_NL_ITEM))
#else
        { "_NL_IDENTIFICATION_TERRITORY", 28 },
#endif
#if defined(_NL_IDENTIFICATION_AUDIENCE) || (defined(_NL_ITEM))
#else
        { "_NL_IDENTIFICATION_AUDIENCE", 27 },
#endif
#if defined(_NL_IDENTIFICATION_APPLICATION) || (defined(_NL_ITEM))
#else
        { "_NL_IDENTIFICATION_APPLICATION", 30 },
#endif
#if defined(_NL_IDENTIFICATION_ABBREVIATION) || (defined(_NL_ITEM))
#else
        { "_NL_IDENTIFICATION_ABBREVIATION", 31 },
#endif
#if defined(_NL_IDENTIFICATION_REVISION) || (defined(_NL_ITEM))
#else
        { "_NL_IDENTIFICATION_REVISION", 27 },
#endif
#if defined(_NL_IDENTIFICATION_DATE) || (defined(_NL_ITEM))
#else
        { "_NL_IDENTIFICATION_DATE", 23 },
#endif
#if defined(_NL_IDENTIFICATION_CATEGORY) || (defined(_NL_ITEM))
#else
        { "_NL_IDENTIFICATION_CATEGORY", 27 },
#endif
#if defined(_NL_MEASUREMENT_MEASUREMENT) || (defined(_NL_ITEM))
#else
        { "_NL_MEASUREMENT_MEASUREMENT", 27 },
#endif
#if defined(_NL_NAME_NAME_FMT) || (defined(_NL_ITEM))
#else
        { "_NL_NAME_NAME_FMT", 17 },
#endif
#if defined(_NL_NAME_NAME_GEN) || (defined(_NL_ITEM))
#else
        { "_NL_NAME_NAME_GEN", 17 },
#endif
#if defined(_NL_NAME_NAME_MR) || (defined(_NL_ITEM))
#else
        { "_NL_NAME_NAME_MR", 16 },
#endif
#if defined(_NL_NAME_NAME_MRS) || (defined(_NL_ITEM))
#else
        { "_NL_NAME_NAME_MRS", 17 },
#endif
#if defined(_NL_NAME_NAME_MISS) || (defined(_NL_ITEM))
#else
        { "_NL_NAME_NAME_MISS", 18 },
#endif
#if defined(_NL_NAME_NAME_MS) || (defined(_NL_ITEM))
#else
        { "_NL_NAME_NAME_MS", 16 },
#endif
#if defined(_NL_PAPER_HEIGHT) || (defined(_NL_ITEM))
#else
        { "_NL_PAPER_HEIGHT", 16 },
#endif
#if defined(_NL_PAPER_WIDTH) || (defined(_NL_ITEM))
#else
        { "_NL_PAPER_WIDTH", 15 },
#endif
#if defined(_NL_TELEPHONE_TEL_INT_FMT) || (defined(_NL_ITEM))
#else
        { "_NL_TELEPHONE_TEL_INT_FMT", 25 },
#endif
#if defined(_NL_TELEPHONE_TEL_DOM_FMT) || (defined(_NL_ITEM))
#else
        { "_NL_TELEPHONE_TEL_DOM_FMT", 25 },
#endif
#if defined(_NL_TELEPHONE_INT_SELECT) || (defined(_NL_ITEM))
#else
        { "_NL_TELEPHONE_INT_SELECT", 24 },
#endif
#if defined(_NL_TELEPHONE_INT_PREFIX) || (defined(_NL_ITEM))
#else
        { "_NL_TELEPHONE_INT_PREFIX", 24 },
#endif
#if defined(CRNCYSTR) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM) && defined(__SVR4_I386_ABI_L1__))
#else
        { "CRNCYSTR", 8 },
#endif
#if defined(THOUSEP) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM) && defined(__SVR4_I386_ABI_L1__))
#else
        { "THOUSEP", 7 },
#endif
#if defined(RADIXCHAR) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM) && defined(__SVR4_I386_ABI_L1__))
#else
        { "RADIXCHAR", 9 },
#endif
        { NULL, 0 } };
struct iv_s {const char *name; I32 namelen; IV value;};
