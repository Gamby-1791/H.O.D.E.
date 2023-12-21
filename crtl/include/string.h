#ifndef _STRING_H
#define _STRING_H

void *memchr (void const *src, char chr, __size_t len);
int memcmp (void const *src, void const *dst, __size_t len);
void memcpy (void *dst, void const *src, __size_t len);
void memmove (void *dst, void const *src, __size_t len);
void memset (void *dst, char chr, __size_t len);
int strcasecmp (char const *a, char const *b);
int strncasecmp (char const *a, char const *b, __size_t len);
char *strchr (char const *s, char c);
int strcmp (char const *a, char const *b);
void strcpy (char *d, char const *s);
char *strdup (char const *s);
__size_t strlen (char const *s);

#endif
