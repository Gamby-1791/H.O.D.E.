//    http://www.gnu.org/licenses/gpl-2.0.html
#ifndef _ASSERT_H
#define _ASSERT_H

#define assert(p) do { if (! (p)) assertfail (__FILE__, __LINE__); } while (0)

void assertfail (char const *file, int line);
void ass_putdbl (double dbl);
void ass_putflt (float flt);
void ass_putstr (char const *str);
void ass_putint (int val);
void ass_putptr (void *ptr);
void ass_putuint (unsigned int val);
void ass_putuinthex (unsigned int val);
void ass_putchr (char chr);
void ass_putbuf (char const *str, int len);

#endif
