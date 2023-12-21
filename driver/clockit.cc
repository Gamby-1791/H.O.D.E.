/**
 * Program runs on raspberry pi to generate clock signal.
 * sudo insmod km/enabtsc.ko
 * sudo ./clockit [200]
 */

#include <stdio.h>
#include <stdlib.h>

#include "gpiolib.h"
#include "miscdefs.h"

int main (int argc, char **argv)
{
    uint32_t cpuhz = DEFCPUHZ;

    if (argc > 1) cpuhz = atoi (argv[1]);

    printf ("cpuhz=%u\n", cpuhz);

    GpioLib *gpio = new PhysLib (cpuhz);
    gpio->open ();

    while (1) {
        gpio->writegpio (false, G_RESET);
        gpio->halfcycle ();
        gpio->writegpio (false, G_RESET | G_CLK);
        gpio->halfcycle ();
    }

    return 0;
}
