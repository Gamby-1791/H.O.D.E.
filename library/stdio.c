#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "fdfile.h"

FILE *stdin;
FILE *stdout;
FILE *stderr;

FILE *fdopen (int fd, char const *mode)
{
    FDFILE *stream = new FDFILE;
    stream->fd = fd;
    return stream;
}

FILE *fopen (char const *path, char const *mode)
{
    int flags = 0;
    for (char c; (c = *mode) != 0; mode ++) {
        switch (c) {
            case 'a': flags = O_APPEND | O_CREAT | O_WRONLY; break;
            case 'b': break;
            case 'r': flags = O_RDONLY; break;
            case 'w': flags = O_CREAT | O_TRUNC | O_WRONLY; break;
            case '+': flags = (flags & ~ O_ACCMODE) | O_RDWR; break;
            default: {
                errno = EINVAL;
                return NULL;
            }
        }
    }

    int fd = open (path, flags, 0666);
    if (fd < 0) return NULL;
    return fdopen (fd, mode);
}

int fclose (FILE *stream)
{
    int rc = stream->fclose ();
    delete stream;
    return rc;
}
