#ifndef _READLINE_H
#define _READLINE_H

struct ReadLine {
    ReadLine ();
    virtual ~ReadLine ();
    int open (int fd);
    void close ();
    char *read (char const *prompt);
    void save (char *linebuff);

    char **histlines;
    int fd;
    int histalloc;
    int histcount;

    int newhistline (int histline, char **linebuff_r, int lineposn, int lineused);
    void writeall (char const *buf, int len);
    void writebks (int size);
    void writespc (int size);
};

#endif
