// copy a bunch of object files into an archive
//  ./archive.x86_64 -o <libfile> <objfile> ...

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Objfile Objfile;

struct Objfile {            // input object file
    Objfile *next;          // next on objfiles list
    char name[1];           // object filename
};

int main (int argc, char **argv)
{
    char const *outname = NULL;
    FILE *outfile;
    int i;
    Objfile **lobjfile, *objfile, *objfiles;

    lobjfile = &objfiles;

    for (i = 0; ++ i < argc;) {
        if (strcasecmp (argv[i], "-o") == 0) {
            outname = argv[++i];
            continue;
        }
        if (argv[i][0] == '-') goto usage;
        objfile = malloc (strlen (argv[i]) + sizeof *objfile);
        strcpy (objfile->name, argv[i]);
        *lobjfile = objfile;
        lobjfile = &objfile->next;
    }
    *lobjfile = NULL;
    if (objfiles == NULL) goto usage;

    outfile = fopen (outname, "w");
    if (outfile == NULL) {
        fprintf (stderr, "error creating %s: %m\n", outname);
        return 1;
    }

    for (objfile = objfiles; objfile != NULL; objfile = objfile->next) {
        char buff[4096];
        FILE *ofile;

        fprintf (outfile, ":%s\n", objfile->name);
        ofile = fopen (objfile->name, "r");
        while (fgets (buff, sizeof buff, ofile) != NULL) {
            fputs (buff, outfile);
        }
        fclose (ofile);
    }
    return 0;

usage:
    fprintf (stderr, "usage: archive -o <outfile> <objfile> ...\n");
    return 1;
}
