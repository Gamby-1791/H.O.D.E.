/**
 * Program runs on any computer to test a physical register board jumpered for R6/R7.
 * Requires four IOW56Paddles connected to the A,C,I,D connectors.
 * sudo insmod km/enabtsc.ko
 * sudo ./writeallonestopc [-cpuhz 200] [-zeroes]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "gpiolib.h"
#include "miscdefs.h"

static GpioLib *gpio;

static void writeccon (uint32_t pins);
static void writedbus (uint16_t dbus);
static void checkabus (uint16_t abus);

int main (int argc, char **argv)
{
    bool zeroes = false;
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
        if (strcasecmp (argv[i], "-zeroes") == 0) {
            zeroes = true;
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

    writeccon (0);
    gpio->halfcycle ();

    while (true) {
        writedbus (0xFFFF);
        writeccon (C_GPRS_WE7 | C_GPRS_REA7);
        gpio->halfcycle ();
        writeccon (C_GPRS_WE7 | C_GPRS_REA7 | C_CLK2);
        gpio->halfcycle ();
        checkabus (0xFFFF);

        if (zeroes) {
            writedbus (0x0000);
            writeccon (C_GPRS_WE7 | C_GPRS_REA7);
            gpio->halfcycle ();
            writeccon (C_GPRS_WE7 | C_GPRS_REA7 | C_CLK2);
            gpio->halfcycle ();
            checkabus (0x0000);
        }
    }

    return 0;
}

// write control output pins that regboards care about
// all other ccon pins get random values
static void writeccon (uint32_t pins)
{
    uint32_t mask = C_CLK2 | C_GPRS_WED | C_GPRS_WE7 | C_GPRS_REA | C_GPRS_REB | C_GPRS_RED2B | C_GPRS_REA7;
    ASSERT ((pins & ~ mask) == 0);
    pins |= rand () & ~ mask;
    if (! gpio->writecon (CON_C, 0xFFFFFFFF, pins)) {
        abort ();
    }
}

// write dbus value that goes to all register dff inputs
// all other dcon pins get random values
static void writedbus (uint16_t dbus)
{
    ASSERT (D_DBUS == 0xFFFF);
    uint32_t pins = GpioLib::dbusshuf (dbus) | (rand () << 16);
    if (! gpio->writecon (CON_D, 0xFFFFFFFF, pins)) {
        abort ();
    }
}

static void checkabus (uint16_t abus)
{
    uint32_t acon;
    if (! gpio->readcon (CON_A, &acon)) {
        abort ();
    }
    uint16_t ais = GpioLib::abussort (acon);
    printf ("abus  is=%04X  sb=%04X  diff=%04X\n", ais, abus, ais ^ abus);
}
