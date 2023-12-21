/**
 * Program runs on raspi mounted to a physical ras bosrd
 * Requires four IOW56Paddles connected to the A,C,I,D connectors.
 * sudo insmod km/enabtsc.ko
 * sudo ./writezeroestoir [-cpuhz 200] 0..7
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "gpiolib.h"
#include "miscdefs.h"

static GpioLib *gpio;

int main (int argc, char **argv)
{
    char *p;
    int regnum = -1;
    uint32_t cpuhz = DEFCPUHZ;

    setlinebuf (stdout);

    for (int i = 0; ++ i < argc;) {
        if (strcasecmp (argv[i], "-cpuhz") == 0) {
            if (++ i >= argc) {
                fprintf (stderr, "-cpuhz missing freq\n");
                return 1;
            }
            cpuhz = atoi (argv[i]);
            continue;
        }
        if (argv[i][0] == '-') {
            fprintf (stderr, "unknown option %s\n", argv[i]);
            return 1;
        }
        if (regnum < 0) {
            regnum = strtol (argv[i], &p, 0);
            if ((*p == 0) && (regnum >= 0) && (regnum <= 7)) continue;
        }
        fprintf (stderr, "unknown argument %s\n", argv[i]);
        return 1;
    }

    // access rasboard circuitry via paddles
    gpio = new PhysLib (cpuhz);
    gpio->open ();

    gpio->writegpio (true, 0);

    if (! gpio->writecon (CON_C, C_SEQ, C__IR_WE ^ C_FLIP)) abort ();

    while (true) {
        sleep (1);
        uint32_t icon;
        if (! gpio->readcon (CON_I, &icon)) abort ();
        uint16_t  ibus = GpioLib::ibussort  (icon);
        uint16_t _ibus = GpioLib::_ibussort (icon);
        printf ("ibus=%04X _ibus=%04X\n", ibus, _ibus);
    }
    return 0;
}
