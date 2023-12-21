#ifndef _FDFILE_H
#define _FDFILE_H

#include <stdio.h>

struct FDFILE : FILE {
    int fd;

    FDFILE ();

    virtual int close ();
    virtual int read (char *buff, int size);
    virtual int write (char *buff, int size);
};

#endif
