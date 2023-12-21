#ifndef _COMPLEX_H
#define _COMPLEX_H

#define CType ComplexD
#define CData double
#include "complex_.h"
#undef CType
#undef CData

#define CType ComplexF
#define CData float
#include "complex_.h"
#undef CType
#undef CData

#endif
