#include <stdio.h>

/*
 * pANS stdio -- vsprintf
 */
#include "/sys/src/ape/lib/ap/stdio/iolib.h"
int snprintf(char *buf, int len, const char *fmt, ...){
	int n;
	char *v;
	va_list va;
	FILE *f=_IO_sopenw();

	va_start(va, fmt);
	if(f==NULL)
		return 0;
	setvbuf(f, buf, _IOFBF, len);
	n=vfprintf(f, fmt, va);
	va_end(va);
	_IO_sclose(f);
	return n;
}
