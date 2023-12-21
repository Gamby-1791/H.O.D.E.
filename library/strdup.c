#include <stdlib.h>
#include <string.h>

char *strdup (char const *s)
{
    __size_t len = strlen (s);
    char *str = malloc (++ len);
    memcpy (str, s, len);
    return str;
}
