#ifndef _CMP_STR_H
#define _CMP_STR_H

#include <string.h>

// https://stackoverflow.com/questions/4157687/using-char-as-a-key-in-stdmap
struct cmp_str
{
   bool operator () (char const *a, char const *b) const
   {
      return strcmp (a, b) < 0;
   }
};

#endif
