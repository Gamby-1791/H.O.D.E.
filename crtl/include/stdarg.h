#ifndef _STDARG_H
#define _STDARG_H

typedef __size_t va_list;

#define va_start(ap,last) do { ap = (__size_t) &__varargs; } while (0)
#define va_end(ap) do { } while (0)
#define va_arg(ap,type) ({ __size_t _ptr = (ap + alignof (type) - 1) & - alignof (type); type _tmp = *(type *)_ptr; ap = _ptr + sizeof (type); _tmp; })

#endif
