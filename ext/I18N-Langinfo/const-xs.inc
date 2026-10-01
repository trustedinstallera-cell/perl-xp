BOOT:
  {
#if defined(dTHX) && !defined(PERL_NO_GET_CONTEXT)
    dTHX;
#endif
    HV *symbol_table = get_hv("I18N::Langinfo::", GV_ADD);

    static const struct iv_s values_for_iv[] =
      {
#ifdef CODESET
        { "CODESET", 7, CODESET },
#endif
#if defined(ABDAY_1) || (defined(_NL_ITEM))
        { "ABDAY_1", 7, ABDAY_1 },
#endif
#if defined(ABDAY_2) || (defined(_NL_ITEM))
        { "ABDAY_2", 7, ABDAY_2 },
#endif
#if defined(ABDAY_3) || (defined(_NL_ITEM))
        { "ABDAY_3", 7, ABDAY_3 },
#endif
#if defined(ABDAY_4) || (defined(_NL_ITEM))
        { "ABDAY_4", 7, ABDAY_4 },
#endif
#if defined(ABDAY_5) || (defined(_NL_ITEM))
        { "ABDAY_5", 7, ABDAY_5 },
#endif
#if defined(ABDAY_6) || (defined(_NL_ITEM))
        { "ABDAY_6", 7, ABDAY_6 },
#endif
#if defined(ABDAY_7) || (defined(_NL_ITEM))
        { "ABDAY_7", 7, ABDAY_7 },
#endif
#if defined(ABMON_1) || (defined(_NL_ITEM))
        { "ABMON_1", 7, ABMON_1 },
#endif
#if defined(ABMON_10) || (defined(_NL_ITEM))
        { "ABMON_10", 8, ABMON_10 },
#endif
#if defined(ABMON_11) || (defined(_NL_ITEM))
        { "ABMON_11", 8, ABMON_11 },
#endif
#if defined(ABMON_12) || (defined(_NL_ITEM))
        { "ABMON_12", 8, ABMON_12 },
#endif
#if defined(ABMON_2) || (defined(_NL_ITEM))
        { "ABMON_2", 7, ABMON_2 },
#endif
#if defined(ABMON_3) || (defined(_NL_ITEM))
        { "ABMON_3", 7, ABMON_3 },
#endif
#if defined(ABMON_4) || (defined(_NL_ITEM))
        { "ABMON_4", 7, ABMON_4 },
#endif
#if defined(ABMON_5) || (defined(_NL_ITEM))
        { "ABMON_5", 7, ABMON_5 },
#endif
#if defined(ABMON_6) || (defined(_NL_ITEM))
        { "ABMON_6", 7, ABMON_6 },
#endif
#if defined(ABMON_7) || (defined(_NL_ITEM))
        { "ABMON_7", 7, ABMON_7 },
#endif
#if defined(ABMON_8) || (defined(_NL_ITEM))
        { "ABMON_8", 7, ABMON_8 },
#endif
#if defined(ABMON_9) || (defined(_NL_ITEM))
        { "ABMON_9", 7, ABMON_9 },
#endif
#if defined(ALT_DIGITS) || (defined(_NL_ITEM))
        { "ALT_DIGITS", 10, ALT_DIGITS },
#endif
#if defined(AM_STR) || (defined(_NL_ITEM))
        { "AM_STR", 6, AM_STR },
#endif
#if defined(DAY_1) || (defined(_NL_ITEM))
        { "DAY_1", 5, DAY_1 },
#endif
#if defined(DAY_2) || (defined(_NL_ITEM))
        { "DAY_2", 5, DAY_2 },
#endif
#if defined(DAY_3) || (defined(_NL_ITEM))
        { "DAY_3", 5, DAY_3 },
#endif
#if defined(DAY_4) || (defined(_NL_ITEM))
        { "DAY_4", 5, DAY_4 },
#endif
#if defined(DAY_5) || (defined(_NL_ITEM))
        { "DAY_5", 5, DAY_5 },
#endif
#if defined(DAY_6) || (defined(_NL_ITEM))
        { "DAY_6", 5, DAY_6 },
#endif
#if defined(DAY_7) || (defined(_NL_ITEM))
        { "DAY_7", 5, DAY_7 },
#endif
#if defined(D_FMT) || (defined(_NL_ITEM))
        { "D_FMT", 5, D_FMT },
#endif
#if defined(D_T_FMT) || (defined(_NL_ITEM))
        { "D_T_FMT", 7, D_T_FMT },
#endif
#if defined(ERA) || (defined(_NL_ITEM))
        { "ERA", 3, ERA },
#endif
#if defined(ERA_D_FMT) || (defined(_NL_ITEM))
        { "ERA_D_FMT", 9, ERA_D_FMT },
#endif
#if defined(ERA_D_T_FMT) || (defined(_NL_ITEM))
        { "ERA_D_T_FMT", 11, ERA_D_T_FMT },
#endif
#if defined(ERA_T_FMT) || (defined(_NL_ITEM))
        { "ERA_T_FMT", 9, ERA_T_FMT },
#endif
#if defined(MON_1) || (defined(_NL_ITEM))
        { "MON_1", 5, MON_1 },
#endif
#if defined(MON_10) || (defined(_NL_ITEM))
        { "MON_10", 6, MON_10 },
#endif
#if defined(MON_11) || (defined(_NL_ITEM))
        { "MON_11", 6, MON_11 },
#endif
#if defined(MON_12) || (defined(_NL_ITEM))
        { "MON_12", 6, MON_12 },
#endif
#if defined(MON_2) || (defined(_NL_ITEM))
        { "MON_2", 5, MON_2 },
#endif
#if defined(MON_3) || (defined(_NL_ITEM))
        { "MON_3", 5, MON_3 },
#endif
#if defined(MON_4) || (defined(_NL_ITEM))
        { "MON_4", 5, MON_4 },
#endif
#if defined(MON_5) || (defined(_NL_ITEM))
        { "MON_5", 5, MON_5 },
#endif
#if defined(MON_6) || (defined(_NL_ITEM))
        { "MON_6", 5, MON_6 },
#endif
#if defined(MON_7) || (defined(_NL_ITEM))
        { "MON_7", 5, MON_7 },
#endif
#if defined(MON_8) || (defined(_NL_ITEM))
        { "MON_8", 5, MON_8 },
#endif
#if defined(MON_9) || (defined(_NL_ITEM))
        { "MON_9", 5, MON_9 },
#endif
#if defined(NOEXPR) || (defined(_NL_ITEM))
        { "NOEXPR", 6, NOEXPR },
#endif
#if defined(NOSTR) || (defined(_NL_ITEM))
        { "NOSTR", 5, NOSTR },
#endif
#if defined(PM_STR) || (defined(_NL_ITEM))
        { "PM_STR", 6, PM_STR },
#endif
#if defined(T_FMT) || (defined(_NL_ITEM))
        { "T_FMT", 5, T_FMT },
#endif
#if defined(T_FMT_AMPM) || (defined(_NL_ITEM))
        { "T_FMT_AMPM", 10, T_FMT_AMPM },
#endif
#if defined(YESEXPR) || (defined(_NL_ITEM))
        { "YESEXPR", 7, YESEXPR },
#endif
#if defined(YESSTR) || (defined(_NL_ITEM))
        { "YESSTR", 6, YESSTR },
#endif
#if defined(_NL_ADDRESS_POSTAL_FMT) || (defined(_NL_ITEM))
        { "_NL_ADDRESS_POSTAL_FMT", 22, _NL_ADDRESS_POSTAL_FMT },
#endif
#if defined(_NL_ADDRESS_COUNTRY_NAME) || (defined(_NL_ITEM))
        { "_NL_ADDRESS_COUNTRY_NAME", 24, _NL_ADDRESS_COUNTRY_NAME },
#endif
#if defined(_NL_ADDRESS_COUNTRY_POST) || (defined(_NL_ITEM))
        { "_NL_ADDRESS_COUNTRY_POST", 24, _NL_ADDRESS_COUNTRY_POST },
#endif
#if defined(_NL_ADDRESS_COUNTRY_AB2) || (defined(_NL_ITEM))
        { "_NL_ADDRESS_COUNTRY_AB2", 23, _NL_ADDRESS_COUNTRY_AB2 },
#endif
#if defined(_NL_ADDRESS_COUNTRY_AB3) || (defined(_NL_ITEM))
        { "_NL_ADDRESS_COUNTRY_AB3", 23, _NL_ADDRESS_COUNTRY_AB3 },
#endif
#if defined(_NL_ADDRESS_COUNTRY_CAR) || (defined(_NL_ITEM))
        { "_NL_ADDRESS_COUNTRY_CAR", 23, _NL_ADDRESS_COUNTRY_CAR },
#endif
#if defined(_NL_ADDRESS_COUNTRY_NUM) || (defined(_NL_ITEM))
        { "_NL_ADDRESS_COUNTRY_NUM", 23, _NL_ADDRESS_COUNTRY_NUM },
#endif
#if defined(_NL_ADDRESS_COUNTRY_ISBN) || (defined(_NL_ITEM))
        { "_NL_ADDRESS_COUNTRY_ISBN", 24, _NL_ADDRESS_COUNTRY_ISBN },
#endif
#if defined(_NL_ADDRESS_LANG_NAME) || (defined(_NL_ITEM))
        { "_NL_ADDRESS_LANG_NAME", 21, _NL_ADDRESS_LANG_NAME },
#endif
#if defined(_NL_ADDRESS_LANG_AB) || (defined(_NL_ITEM))
        { "_NL_ADDRESS_LANG_AB", 19, _NL_ADDRESS_LANG_AB },
#endif
#if defined(_NL_ADDRESS_LANG_TERM) || (defined(_NL_ITEM))
        { "_NL_ADDRESS_LANG_TERM", 21, _NL_ADDRESS_LANG_TERM },
#endif
#if defined(_NL_ADDRESS_LANG_LIB) || (defined(_NL_ITEM))
        { "_NL_ADDRESS_LANG_LIB", 20, _NL_ADDRESS_LANG_LIB },
#endif
#if defined(_NL_IDENTIFICATION_TITLE) || (defined(_NL_ITEM))
        { "_NL_IDENTIFICATION_TITLE", 24, _NL_IDENTIFICATION_TITLE },
#endif
#if defined(_NL_IDENTIFICATION_SOURCE) || (defined(_NL_ITEM))
        { "_NL_IDENTIFICATION_SOURCE", 25, _NL_IDENTIFICATION_SOURCE },
#endif
#if defined(_NL_IDENTIFICATION_ADDRESS) || (defined(_NL_ITEM))
        { "_NL_IDENTIFICATION_ADDRESS", 26, _NL_IDENTIFICATION_ADDRESS },
#endif
#if defined(_NL_IDENTIFICATION_CONTACT) || (defined(_NL_ITEM))
        { "_NL_IDENTIFICATION_CONTACT", 26, _NL_IDENTIFICATION_CONTACT },
#endif
#if defined(_NL_IDENTIFICATION_EMAIL) || (defined(_NL_ITEM))
        { "_NL_IDENTIFICATION_EMAIL", 24, _NL_IDENTIFICATION_EMAIL },
#endif
#if defined(_NL_IDENTIFICATION_TEL) || (defined(_NL_ITEM))
        { "_NL_IDENTIFICATION_TEL", 22, _NL_IDENTIFICATION_TEL },
#endif
#if defined(_NL_IDENTIFICATION_FAX) || (defined(_NL_ITEM))
        { "_NL_IDENTIFICATION_FAX", 22, _NL_IDENTIFICATION_FAX },
#endif
#if defined(_NL_IDENTIFICATION_LANGUAGE) || (defined(_NL_ITEM))
        { "_NL_IDENTIFICATION_LANGUAGE", 27, _NL_IDENTIFICATION_LANGUAGE },
#endif
#if defined(_NL_IDENTIFICATION_TERRITORY) || (defined(_NL_ITEM))
        { "_NL_IDENTIFICATION_TERRITORY", 28, _NL_IDENTIFICATION_TERRITORY },
#endif
#if defined(_NL_IDENTIFICATION_AUDIENCE) || (defined(_NL_ITEM))
        { "_NL_IDENTIFICATION_AUDIENCE", 27, _NL_IDENTIFICATION_AUDIENCE },
#endif
#if defined(_NL_IDENTIFICATION_APPLICATION) || (defined(_NL_ITEM))
        { "_NL_IDENTIFICATION_APPLICATION", 30, _NL_IDENTIFICATION_APPLICATION },
#endif
#if defined(_NL_IDENTIFICATION_ABBREVIATION) || (defined(_NL_ITEM))
        { "_NL_IDENTIFICATION_ABBREVIATION", 31, _NL_IDENTIFICATION_ABBREVIATION },
#endif
#if defined(_NL_IDENTIFICATION_REVISION) || (defined(_NL_ITEM))
        { "_NL_IDENTIFICATION_REVISION", 27, _NL_IDENTIFICATION_REVISION },
#endif
#if defined(_NL_IDENTIFICATION_DATE) || (defined(_NL_ITEM))
        { "_NL_IDENTIFICATION_DATE", 23, _NL_IDENTIFICATION_DATE },
#endif
#if defined(_NL_IDENTIFICATION_CATEGORY) || (defined(_NL_ITEM))
        { "_NL_IDENTIFICATION_CATEGORY", 27, _NL_IDENTIFICATION_CATEGORY },
#endif
#if defined(_NL_MEASUREMENT_MEASUREMENT) || (defined(_NL_ITEM))
        { "_NL_MEASUREMENT_MEASUREMENT", 27, _NL_MEASUREMENT_MEASUREMENT },
#endif
#if defined(_NL_NAME_NAME_FMT) || (defined(_NL_ITEM))
        { "_NL_NAME_NAME_FMT", 17, _NL_NAME_NAME_FMT },
#endif
#if defined(_NL_NAME_NAME_GEN) || (defined(_NL_ITEM))
        { "_NL_NAME_NAME_GEN", 17, _NL_NAME_NAME_GEN },
#endif
#if defined(_NL_NAME_NAME_MR) || (defined(_NL_ITEM))
        { "_NL_NAME_NAME_MR", 16, _NL_NAME_NAME_MR },
#endif
#if defined(_NL_NAME_NAME_MRS) || (defined(_NL_ITEM))
        { "_NL_NAME_NAME_MRS", 17, _NL_NAME_NAME_MRS },
#endif
#if defined(_NL_NAME_NAME_MISS) || (defined(_NL_ITEM))
        { "_NL_NAME_NAME_MISS", 18, _NL_NAME_NAME_MISS },
#endif
#if defined(_NL_NAME_NAME_MS) || (defined(_NL_ITEM))
        { "_NL_NAME_NAME_MS", 16, _NL_NAME_NAME_MS },
#endif
#if defined(_NL_PAPER_HEIGHT) || (defined(_NL_ITEM))
        { "_NL_PAPER_HEIGHT", 16, _NL_PAPER_HEIGHT },
#endif
#if defined(_NL_PAPER_WIDTH) || (defined(_NL_ITEM))
        { "_NL_PAPER_WIDTH", 15, _NL_PAPER_WIDTH },
#endif
#if defined(_NL_TELEPHONE_TEL_INT_FMT) || (defined(_NL_ITEM))
        { "_NL_TELEPHONE_TEL_INT_FMT", 25, _NL_TELEPHONE_TEL_INT_FMT },
#endif
#if defined(_NL_TELEPHONE_TEL_DOM_FMT) || (defined(_NL_ITEM))
        { "_NL_TELEPHONE_TEL_DOM_FMT", 25, _NL_TELEPHONE_TEL_DOM_FMT },
#endif
#if defined(_NL_TELEPHONE_INT_SELECT) || (defined(_NL_ITEM))
        { "_NL_TELEPHONE_INT_SELECT", 24, _NL_TELEPHONE_INT_SELECT },
#endif
#if defined(_NL_TELEPHONE_INT_PREFIX) || (defined(_NL_ITEM))
        { "_NL_TELEPHONE_INT_PREFIX", 24, _NL_TELEPHONE_INT_PREFIX },
#endif
#if defined(CRNCYSTR) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM) && defined(__SVR4_I386_ABI_L1__))
        { "CRNCYSTR", 8, CRNCYSTR },
#endif
#if defined(THOUSEP) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM) && defined(__SVR4_I386_ABI_L1__))
        { "THOUSEP", 7, THOUSEP },
#endif
#if defined(RADIXCHAR) || (defined(__GNU_LIBRARY__) && defined(_NL_ITEM) && defined(__SVR4_I386_ABI_L1__))
        { "RADIXCHAR", 9, RADIXCHAR },
#endif
        { NULL, 0, 0 } };
	const struct iv_s *value_for_iv = values_for_iv;
        while (value_for_iv->name) {
	    constant_add_symbol(aTHX_  symbol_table, value_for_iv->name,
				value_for_iv->namelen, newSViv(value_for_iv->value));
            ++value_for_iv;
	}
	if (C_ARRAY_LENGTH(values_for_notfound) > 1) {
#ifndef SYMBIAN
	    HV *const constant_missing = get_missing_hash(aTHX);
#endif
	    const struct notfound_s *value_for_notfound = values_for_notfound;
	    do {

		/* Need to add prototypes, else parsing will vary by platform.  */
		HE *he = (HE*) hv_common_key_len(symbol_table,
						 value_for_notfound->name,
						 value_for_notfound->namelen,
						 HV_FETCH_LVALUE, NULL, 0);
		SV *sv;
#ifndef SYMBIAN
		HEK *hek;
#endif
		if (!he) {
		    croak("Couldn't add key '%s' to %%I18N::Langinfo::",
			  value_for_notfound->name);
		}
		sv = HeVAL(he);
		if (!SvOK(sv) && SvTYPE(sv) != SVt_PVGV) {
		    /* Nothing was here before, so mark a prototype of ""  */
		    sv_setpvn(sv, "", 0);
		} else if (SvPOK(sv) && SvCUR(sv) == 0) {
		    /* There is already a prototype of "" - do nothing  */
		} else {
		    /* Someone has been here before us - have to make a real
		       typeglob.  */
		    /* It turns out to be incredibly hard to deal with all the
		       corner cases of sub foo (); and reporting errors correctly,
		       so lets cheat a bit.  Start with a constant subroutine  */
		    CV *cv = newCONSTSUB(symbol_table,
					 value_for_notfound->name,
					 &PL_sv_yes);
		    /* and then turn it into a non constant declaration only.  */
		    SvREFCNT_dec(CvXSUBANY(cv).any_ptr);
		    CvCONST_off(cv);
		    CvXSUB(cv) = NULL;
		    CvXSUBANY(cv).any_ptr = NULL;
		}
#ifndef SYMBIAN
		hek = HeKEY_hek(he);
		if (!hv_common(constant_missing, NULL, HEK_KEY(hek),
 			       HEK_LEN(hek), HEK_FLAGS(hek), HV_FETCH_ISSTORE,
			       &PL_sv_yes, HEK_HASH(hek)))
		    croak("Couldn't add key '%s' to missing_hash",
			  value_for_notfound->name);
#endif
	    } while ((++value_for_notfound)->name);
	}
    /* As we've been creating subroutines, we better invalidate any cached
       methods  */
    mro_method_changed_in(symbol_table);
  }

void
AUTOLOAD()
    PROTOTYPE: DISABLE
    PREINIT:
	SV *sv = newSVpvn_flags(SvPVX(cv), SvCUR(cv), SVs_TEMP | SvUTF8(cv));
	const COP *cop = PL_curcop;
    PPCODE:
#ifndef SYMBIAN
	/* It's not obvious how to calculate this at C pre-processor time.
	   However, any compiler optimiser worth its salt should be able to
	   remove the dead code, and hopefully the now-obviously-unused static
	   function too.  */
	HV *constant_missing = (C_ARRAY_LENGTH(values_for_notfound) > 1)
	    ? get_missing_hash(aTHX) : NULL;
	if ((C_ARRAY_LENGTH(values_for_notfound) > 1)
	    ? hv_exists_ent(constant_missing, sv, 0) : 0) {
	    sv = newSVpvf("Your vendor has not defined I18N::Langinfo macro %" SVf
			  ", used at %" COP_FILE_F " line %" UVuf "\n", 
			  sv, COP_FILE(cop), (UV)CopLINE(cop));
	} else
#endif
	{
	    sv = newSVpvf("%" SVf
                          " is not a valid I18N::Langinfo macro at %"
			  COP_FILE_F " line %" UVuf "\n",
			  sv, COP_FILE(cop), (UV)CopLINE(cop));
	}
	croak_sv(sv_2mortal(sv));
