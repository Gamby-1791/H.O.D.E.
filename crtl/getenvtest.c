// print out envars listed on command line

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    for (int i = 0; ++ i < argc;) {
        char const *name = argv[i];
        char *env = getenv (name);
        if (env == NULL) {
            printf ("<%s> missing\n", name);
        } else {
            printf ("<%s> = %p <%s>\n", name, env, env);
        }
    }
    return 0;
}
