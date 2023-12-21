#include <errno.h>
#include <math.h>
#include <stdlib.h>

FType strto_ (char const *nptr, char **endptr)
{
    FType value = 0.0;

    // skip leading spaces
    char ch;
    while (((ch = *nptr) <= ' ') && (ch != 0)) nptr ++;

    // check for NAN
    if (((ch & 0xDF) == 'N') && ((nptr[1] & 0xDF) == 'A') && ((nptr[2] & 0xDF) == 'N')) {
        nptr += 3;
        value = NAN;
    } else {
        bool valid = 0;

        // check for leading +-
        bool negative = 0;
        if (ch == '-') {
            negative = 1;
            ch = *(++ nptr);
        } else if (ch == '+') {
            ch = *(++ nptr);
        }

        // check for INF
        if (((ch & 0xDF) == 'I') && ((nptr[1] & 0xDF) == 'N') && ((nptr[2] & 0xDF) == 'F')) {
            nptr += 3;
            value = INF;
            valid = 1;
        } else if ((ch == '0') && ((nptr[1] & 0xDF) == 'X')) {
            ++ nptr;

            // hexadecimal digits before decimal point
            while (1) {
                ch = *(++ nptr);
                if (ch < '0') break;
                if (ch > '9') {
                    ch &= 0xDF;
                    if (ch < 'A') break;
                    if (ch > 'F') break;
                    ch += '0' + 10 - 'A';
                    valid = 1;
                }
                value *= 16.0;
                value += ch - '0';
            }

            // hexadecimal digits after decimal point
            if (ch == '.') {
                FType divby = 1.0;
                while (1) {
                    ch = *(++ nptr);
                    if (ch < '0') break;
                    if (ch > '9') {
                        ch &= 0xDF;
                        if (ch < 'A') break;
                        if (ch > 'F') break;
                        ch += '0' + 10 - 'A';
                        valid = 1;
                    }
                    divby *= 16.0;
                    value += (ch - '0') / divby;
                }
            }

            // exponent
            if ((ch & 0xDF) == 'P') {

                // check for leading +-
                bool negexp = 0;
                ch = *(++ nptr);
                if (ch == '-') {
                    negexp = 1;
                    ch = *(++ nptr);
                } else if (ch == '+') {
                    ch = *(++ nptr);
                }

                // accumulate digits
                unsigned int exponent = 0;
                while ((ch >= '0') && (ch <= '9')) {
                    exponent = exponent * 10 + (ch - '0');
                    ch = *(++ nptr);
                }

                // apply power-of-two exponent to value
                value = FMath (ldexp) (value, negexp ? - exponent : exponent);
            }
        } else {

            // decimal digits before decimal point
            while ((ch >= '0') && (ch <= '9')) {
                value *= 10.0;
                value += ch - '0';
                ch = *(++ nptr);
                valid = 1;
            }

            // decimal digits after decimal point
            if (ch == '.') {
                FType divby = 1.0;
                while (((ch = *(++ nptr)) >= '0') && (ch <= '9')) {
                    divby *= 10.0;
                    value += (ch - '0') / divby;
                    valid = 1;
                }
            }

            // exponent
            if ((ch & 0xDF) == 'E') {

                // check for leading +-
                bool negexp = 0;
                ch = *(++ nptr);
                if (ch == '-') {
                    negexp = 1;
                    ch = *(++ nptr);
                } else if (ch == '+') {
                    ch = *(++ nptr);
                }

                // accumulate digits
                unsigned int exponent = 0;
                while ((ch >= '0') && (ch <= '9')) {
                    exponent = exponent * 10 + (ch - '0');
                    ch = *(++ nptr);
                }

                // apply power-of-10 exponent to value
                FType expmult = negexp ? (FType) 0.1 : (FType) 10.0;
                while (exponent > 0) {
                    if (exponent & 1) {
                        value *= expmult;
                    }
                    expmult *= expmult;
                    exponent /= 2;
                }
            }
        }

        if (! valid) errno = EINVAL;
        if (negative) value = - value;
    }

    if (endptr != NULL) *endptr = (char *) nptr;
    return value;
}
