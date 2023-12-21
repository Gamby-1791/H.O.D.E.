#ifndef _MISCDEFS_H
#define _MISCDEFS_H

typedef signed char sint8_t;
typedef short sint16_t;
typedef int sint32_t;
typedef long long sint64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

#define ASSERT(cond) do { if (__builtin_constant_p (cond)) { if (!(cond)) asm volatile ("assert failure"); } else { if (!(cond)) abort (); } } while (0)

#define REGA 10
#define REGD  7
#define REGB  4

#endif
