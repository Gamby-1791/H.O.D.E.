#include <assert.h>

int main (int argc, char **argv)
{
    for (int i = 0; i < argc; i ++) {
        ass_putstr ("main*: argv["); ass_putint (i); ass_putstr ("]="); ass_putstr (argv[i]); ass_putchr ('\n');
    }
    ass_putstr ("main*: done\n");
    return argc;
}
