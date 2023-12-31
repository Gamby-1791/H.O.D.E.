#include <assert.h>
#include <hode.h>
#include <stdio.h>
#include <stdlib.h>

extern char __endro[];

void _start ()
{
    setrosize ((__size_t) __endro);

    stdin  = fdopen (0, "r");
    stdout = fdopen (1, "w");
    stderr = fdopen (2, "w");

    // count command-line args given to raspictl
    // and count total char length
    int totlen = 0;
    int argc;
    for (argc = 0;; argc ++) {
        int argl = getcmdarg (argc, 0, NULL);
        if (argl < 0) break;
        totlen += argl + 1;
    }

    // allocate command-line arg buffer and fill it in
    char *argbuf = malloc (totlen);
    char **argv = malloc ((argc + 1) * sizeof *argv);
    for (argc = 0;; argc ++) {
        int argl = getcmdarg (argc, totlen, argbuf);
        if (argl < 0) break;
        argv[argc] = argbuf;
        argbuf += argl + 1;
        totlen -= argl + 1;
    }
    argv[argc] = NULL;

    // call main function then exit
    int rc = 255;
    try {
        rc = main (argc, argv);
        fclose (stdin);
        fclose (stdout);
        fclose (stderr);
    } catch (char const *e) {
        ass_putstr ("_start: uncaught char const *exception: ");
        ass_putstr (e);
        ass_putchr ('\n');
    } catch (char *e) {
        ass_putstr ("_start: uncaught char *exception: ");
        ass_putstr (e);
        ass_putchr ('\n');
    } catch (void *e, void const *const *typeid) {
        ass_putstr ("_start: uncaught ");
        ass_putstr (*(char const *const *) typeid);
        ass_putstr (" *exception ");
        ass_putptr (e);
        ass_putchr ('\n');
    }
    while (1) exit (rc);
}
