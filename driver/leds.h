#include <curses.h>

#include "miscdefs.h"

struct LEDS {
    LEDS (char const *ttyname);
    ~LEDS ();
    void update (uint32_t acon, uint32_t ccon, uint32_t icon, uint32_t dcon);

private:
    SCREEN *screen;
    WINDOW *window;
};

