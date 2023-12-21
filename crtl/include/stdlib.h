#ifndef _STDLIB_H
#define _STDLIB_H

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef int qsortcompar_t (void const *a, void const *b);

void          abort   ();
__size_t      allocsz (void *ptr);
void         *calloc  (__size_t nmem, __size_t size);
void          exit    (int status);
void          free    (void *ptr);
char         *getenv  (char const *name);
int           main    (int argc, char **argv);
void         *malloc  (__size_t size);
void          qsort   (void *base, __size_t nmemb, __size_t size, qsortcompar_t *compar);
void         *realloc (void *ptr, __size_t size);
double        strtod  (char const *nptr, char **endptr);
float         strtof  (char const *nptr, char **endptr);
long          strtol  (char const *nptr, char **endptr, unsigned int base);
unsigned long strtoul (char const *nptr, char **endptr, unsigned int base);

#endif
