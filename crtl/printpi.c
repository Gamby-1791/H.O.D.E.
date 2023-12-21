#include <stdio.h>

int main (int argc, char **argv)
{
    double piapprox = 3.0;
    for (__uint16_t denom = 3; denom < 37600U; denom += 2) {
        double diff = 4.0 / ((denom - 1) * (double) denom * (denom + 1));
        if (denom & 2) {
            piapprox += diff;
        } else {
            piapprox -= diff;
        }
        printf ("\r%6u : pi=%16.13lf  ", denom, piapprox);
        fflush (stdout);
    }
    printf ("\n");
    return 0;
}
