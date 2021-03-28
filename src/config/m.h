#if defined(T386)
	#undef MOSML_BIG_ENDIAN
	#undef ALIGNMENT
#elif defined(Tmips)
	#define MOSML_BIG_ENDIAN
	#define ALIGNMENT
#elif defined(Talpha)
	#define MOSML_BIG_ENDIAN
	#define ALIGNMENT
#endif
