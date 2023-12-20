// calculate value for base shunt resistor
//  rb = 4.7K: 300nS turn-off time
//  rb = 1.0K: 100nS turn-off time

// datasheet (ON semiconductor) for 2N3904
// says beta minimum is 60 at ic = 50mA
//                     100 at ic = 10mA

/*
                vcc                vcc
                 |                  |
                ra                 rc
                 |                  |
                 |                  +-----vout
                 |                  |
                 |                  /
    vin-----|<---+---|<---|<---+---|
                               |    \
                              rb    |
                               |    |
                               |  gnd
                               |
                              vbb
*/

#include <stdio.h>

int main ()
{
    double ra = 2.7;
    double rc = 0.68;
    double vcc = 5;

    double rb;
    int beta, fan, vbb;

    // current flowing thru input pullup when input is high
    double ia = (vcc - 3 * 0.7) / ra;

    printf ("fan    ic    rl       20       25       30       35       40       45       50       55       60\n");

    for (vbb = 0; vbb <= 0; vbb += 5) {

        printf ("\nvbb %2d\n", vbb);

        for (fan = 0; fan <= 10; fan ++) {

            // current thru collector for that fanout
            double ic = vcc / rc + fan * (vcc - 0.7) / ra;
            printf ("%3d  %4.1fma  %3d", fan, ic, (int) (vcc / ic * 1000.0 + 0.5));

            for (beta = 20; beta <= 60; beta += 5) {

                // minimum current needed thru base for that collector current
                double ib = ic / beta;

                // excess can be shunted thru base resistor
                double rb = (0.7 + vbb) / (ia - ib);

                printf ("%9d", (int) (rb * 1000.0 + 0.5));
            }

            printf ("\n");
        }
    }
    return 0;
}
