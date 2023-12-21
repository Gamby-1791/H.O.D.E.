#ifndef _VFPRINTF_H
#define _VFPRINTF_H

#include <stdio.h>

typedef  __int8_t   Byte;
typedef  __int16_t  Word;
typedef  __int32_t  Long;
typedef  __int64_t  Quad;

typedef __uint8_t  uByte;
typedef __uint16_t uWord;
typedef __uint32_t uLong;
typedef __uint64_t uQuad;

#define Par     vfprintf_Par
#define putint  vfprintf_putint
#define putsign vfprintf_putsign
#define putfc   vfprintf_putfc
#define putst   vfprintf_putst
#define putch   vfprintf_putch

/* Get unsigned short/long/int into 'unum' */

#define GETUNSIGNEDNUM vfprintf_getunum (p)

/* Get short/long/int into '(u/s)num', put the sign in 'negative' */

#define GETSIGNEDNUM vfprintf_getsnum (p)

/* Get floating point into fnum and expon:  fnum normalised in range 1.0 (inclusive) to 10.0 (exclusive) such that original_value = fnum * 10 ** expon */

#define GETFLOATNUM(scale) if (! vfprintf_getfnum (p, scale)) goto infnan

/* Parameter block passed to various 'put' routines */

struct Par { int minwidth;          /* mininum output field width */
             int precision;         /* number of decimal places to output */
             int negative;          /* number being output requires a '-' sign */
             int altform;           /* output it in alternative format */
             int zeropad;           /* right justify, zero fill */
             int leftjust;          /* left justify, blank fill */
             int posblank;          /* if positive, output a space for the sign */
             int plussign;          /* if positive, output a '+' for the sign */
             int intsize;           /* integer size: 1=Byte, 2=Word, 4=Long, 8=Quad */
             int fltsize;           /* float size: 4=float, 8=double */

             FILE *stream;

             char *ncp;             /* start of integer string to output */
             char *nce;             /* end of integer string to output */

             char const *nfe;       /* number format error */

             va_list  ap;
             uQuad  unum;
             double fnum;
             int   expon;

             int numout;            /* total number of characters output so far */
           };

/* 'Put' routines output common stuff to the output buffer */

#define PUTLEFTFILL(__n) do { if (!(p -> leftjust) && !(p -> zeropad)) PUTFC (p -> minwidth - (__n), ' '); } while (0)
#define PUTLEFTZERO(__n) do { if (!(p -> leftjust) &&  (p -> zeropad)) PUTFC (p -> minwidth - (__n), '0'); } while (0)
#define PUTRIGHTFILL     PUTFC (p -> minwidth, ' ')

#define PUTINT(__alt)  do { sts = putint (p, __alt);   if (sts < 0) return (sts); } while (0)
#define PUTSIGN        do { sts = putsign (p);         if (sts < 0) return (sts); } while (0)
#define PUTFC(__s,__c) do { sts = putfc (p, __s, __c); if (sts < 0) return (sts); } while (0)
#define PUTST(__s,__b) do { sts = putst (p, __s, __b); if (sts < 0) return (sts); } while (0)
#define PUTCH(__c)     do { sts = putch (p, __c);      if (sts < 0) return (sts); } while (0)

/* Round normalised floating point number 'floatnum' to the given number of digits of precision following the decimal point */

#define ROUNDFLOAT(prec) vfprintf_roundflt (p, prec)

/* Get integer in format string.  If *, use next integer argument, otherwise use decimal string */

#define GETFMTINT(fi) fp = vfprintf_getfmtint (p, fp, &fi)

int vfprintf_fp (char fc, Par *p, va_list ap, va_list *ap_r);
int putint  (Par *p, char const *alt);
int putsign (Par *p);
int putfc   (Par *p, int s, char c);
int putst   (Par *p, int s, char const *b);
int putch   (Par *p, char c);
void vfprintf_getunum (Par *p);
void vfprintf_getsnum (Par *p);
int  vfprintf_getfnum (Par *p, bool scale);
void vfprintf_roundflt (Par *p, int prec);
char const *vfprintf_getfmtint (Par *p, char const *fp, int *fi_r);

#endif
