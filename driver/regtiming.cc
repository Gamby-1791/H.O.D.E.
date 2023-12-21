/**
 * Program runs on any computer to test timing of a physical register board.
 * Requires four IOW56Paddles connected to the A,C,I,D connectors.
 * Assumes board is jumpered as R6/R7 and was tested with regtester.
 * sudo insmod km/enabtsc.ko
 * sudo ./regtiming [-cpuhz 200]
 * Connect one probe to CLK2.
 * Connect other to an abus/bbus output.
 * Data outputs alternate every clock cycle.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gpiolib.h"
#include "miscdefs.h"

static GpioLib *gpio;

static void writeccon (uint32_t pins);

int main (int argc, char **argv)
{
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
        fprintf (stderr, "unknown argument %s\n", argv[i]);
        return 1;
    }

    // access regboard circuitry via paddles
    gpio = new PhysLib (cpuhz);
    gpio->open ();

    // select R6 as A,B,D registers
    uint16_t ir = (6 << REGA) | (6 << REGB) | (6 << REGD);
    uint32_t ir32 = GpioLib::ibusshuf (ir);
    if (! gpio->writecon (CON_I, 0xFFFFFFFF, ir32)) {
        abort ();
    }

    uint32_t dcon0 = GpioLib::dbusshuf (0x6666);
    uint32_t dcon1 = GpioLib::dbusshuf (0x9999);

    while (true) {
        writeccon (C_GPRS_WED | C_GPRS_WE7 | C_GPRS_REA7 | C_GPRS_REB);
        if (! gpio->writecon (CON_D, 0xFFFFFFFF, dcon0)) {
            abort ();
        }
        gpio->halfcycle ();

        writeccon (C_GPRS_WED | C_GPRS_WE7 | C_GPRS_REA7 | C_GPRS_REB | C_CLK2);
        gpio->halfcycle ();

        writeccon (C_GPRS_WED | C_GPRS_WE7 | C_GPRS_REA7 | C_GPRS_REB);
        if (! gpio->writecon (CON_D, 0xFFFFFFFF, dcon1)) {
            abort ();
        }
        gpio->halfcycle ();

        writeccon (C_GPRS_WED | C_GPRS_WE7 | C_GPRS_REA7 | C_GPRS_REB | C_CLK2);
        gpio->halfcycle ();
    }

    return 0;
}

// write control output pins that regboards care about
static void writeccon (uint32_t pins)
{
    uint32_t mask = C_CLK2 | C_GPRS_WED | C_GPRS_WE7 | C_GPRS_REA | C_GPRS_REB | C_GPRS_RED2B | C_GPRS_REA7;
    ASSERT ((pins & ~ mask) == 0);
    if (! gpio->writecon (CON_C, 0xFFFFFFFF, pins)) {
        abort ();
    }
}
