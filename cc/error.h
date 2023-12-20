#ifndef _ERROR_H
#define _ERROR_H

#include "token.h"

struct Error {
    Error (Token *tok, char *buf);
    virtual ~Error ();

    Token *getToken () { return tok; }
    char const *getBuf () { return buf; }

private:
    Token *tok;
    char *buf;
};

void handlerror (Error *err);
void printerror (Token *tok, char const *fmt, ...);
void throwerror (Token *tok, char const *fmt, ...) __attribute__ ((__noreturn__));

#endif
