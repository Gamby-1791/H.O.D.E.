#ifndef _MYTYPES_H
#define _MYTYPES_H

#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#define TEXTPSECT ".50.text"
#define DATAPSECT ".70.data"

#define CARROFFS -2         // must match __malloc2()
#define RETBYVALSIZE 4
#define MAXALIGN 2
typedef uint16_t tsize_t;

extern FILE *sfile;
extern bool errorflag;

#define assert_false() do { assert (false); } while (true)

#endif
