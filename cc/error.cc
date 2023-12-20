#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "error.h"

void handlerror (Error *err)
{
    printerror (err->getToken (), "%s", err->getBuf ());
    delete err;
    int braces = 0;
    while (true) {
        Token *tok = gettoken ();
        switch (tok->getKw ()) {
            case KW_OBRACE: {
                braces ++;
                break;
            }
            case KW_CBRACE: {
                if (-- braces <= 0) {
                    if (braces < 0) pushtoken (tok);
                    return;
                }
                break;
            }
            case KW_EOF: return;
            case KW_SEMI: {
                if (braces <= 0) return;
                break;
            }
            default: break;
        }
    }
}

void printerror (Token *tok, char const *fmt, ...)
{
    va_list ap;
    char *buf;
    va_start (ap, fmt);
    vasprintf (&buf, fmt, ap);
    va_end (ap);
    fprintf (stderr, "%s:%d.%d: %s\n", tok->getFile (), tok->getLine (), tok->getColn (), buf);
    free (buf);
    errorflag = true;
}

void throwerror (Token *tok, char const *fmt, ...)
{
    char *buf;
    va_list ap;
    va_start (ap, fmt);
    vasprintf (&buf, fmt, ap);
    va_end (ap);
    throw new Error (tok, buf);
}

Error::Error (Token *tok, char *buf)
{
    this->tok = tok;
    this->buf = buf;
}

Error::~Error ()
{
    free (buf);
    buf = nullptr;
}
