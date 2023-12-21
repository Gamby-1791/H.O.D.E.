// simulate processor via shadow

#include "gpiolib.h"
#include "shadow.h"

NohwLib::NohwLib (Shadow *shadow)
{
    this->shadow = shadow;
}

void NohwLib::open ()
{ }

void NohwLib::close ()
{ }

void NohwLib::halfcycle ()
{ }

uint32_t NohwLib::readgpio ()
{
    uint32_t value = shadow->readgpio ();
    value = (value & ~ G_OUTS) | (gpiowritten & G_OUTS);
    if (value & G__QENA) {
        value = (value & ~ G_DATA) | (gpiowritten & G_DATA);
    }
    return value;
}

void NohwLib::writegpio (bool wdata, uint32_t value)
{
    gpiowritten = value | (wdata ? G__QENA : G_DATA);
}

bool NohwLib::readcon (IOW56Con c, uint32_t *pins)
{
    return false;
}

bool NohwLib::writecon (IOW56Con c, uint32_t mask, uint32_t pins)
{
    return false;
}
