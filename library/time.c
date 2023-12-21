#include <hode.h>
#include <stdlib.h>
#include <time.h>

time_t time (time_t *tp)
{
    time_t t = getnowns () / 1000000000;
    if (tp != NULL) *tp = t;
    return t;
}
