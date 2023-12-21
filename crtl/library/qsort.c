#include <stdlib.h>

static void partsort (char *base, __size_t beg, __size_t end, __size_t size, qsortcompar_t *compar);
static void swapelem (char *a, char *b, __size_t size);

void qsort (void *base, __size_t nmemb, __size_t size, qsortcompar_t *compar)
{
    if ((size > 0) && (nmemb > 1)) {
        partsort (base, 0, nmemb - 1, size, compar);
    }
}

static void partsort (char *base, __size_t beg, __size_t end, __size_t size, qsortcompar_t *compar)
{
resort:
    if (end > beg + 3) {
        __size_t ppp = end;
        __size_t bbb = beg;
        __size_t eee = end - 1;

        char *p = base + size * ppp;
        char *b = base + size * bbb;
        char *e = base + size * eee;

        while (1) {
            while ((bbb < ppp) && (compar (b, p) <= 0)) { bbb ++; b += size; }
            if (bbb == ppp) {
                -- end;
                goto resort;
            }
            // bbb = some element gt pivot

            while ((eee > bbb) && (compar (e, p) >= 0)) { eee --; e -= size; }
            if (eee == bbb) {
                swapelem (b, p, size);
                // [beg..bbb-1] = all le pivot
                // [bbb] = eq pivot
                // [bbb+1..end] = all ge pivot
                if (bbb > beg) partsort (base, beg, bbb - 1, size, compar);
                beg = bbb + 1;
                goto resort;
            }
            // eee = some element lt pivot

            swapelem (b, e, size);
            bbb ++;
            b += size;
        }
    } else if (end > beg) {
        __size_t nmemb = end - beg + 1;
        base += size * beg;
        do {
            __size_t j = -- nmemb;
            char *a = base;
            do {
                char *b = a + size;
                if (compar (a, b) > 0) {
                    swapelem (a, b, size);
                }
                a = b;
            } while (-- j > 0);
        } while (nmemb > 1);
    }
}

static void swapelem (char *a, char *b, __size_t size)
{
    do {
        char c = *a;
        *(a ++) = *b;
        *(b ++) = c;
    } while (-- size > 0);
}
