struct Blob {
    __int32_t someint;
    char      somechar;
    __int16_t someshorts[12];
    Blob     *nextinlist;
};

void putc (char chr);
void puts (char const *str);

char buf[80];
int frac = 123 / 4;

int whoratio (int a, int b)
{
    puts ("hello world\n");
    int iyi;
    iyi = sizeof 1145;
    iyi = sizeof (__uint64_t);
    iyi = sizeof buf;
    iyi = sizeof "size incl null";
    iyi = sizeof (Blob);
    for (iyi = 0; iyi < 10U; iyi ++) {
        buf[0] = (char) iyi + '0';
        buf[1] = '\n';
        buf[2] = 0;
        puts (buf);
    }
    for (iyi = 0; iyi < 3; iyi ++) {
        char c;
        c = buf[iyi];
        putc (c);

        static short accum = 34;
        if (! (iyi & 1)) {
            accum += accum;
        }

        switch (iyi) {
            default: puts ("default");
            case 0: puts ("zero\n");
            case 2: puts ("two\n"); break;
            case 1: puts ("one\n");
            case 3: puts ("three\n"); break;
        }

        puts ((iyi == 1) ? "singular\n" : "plural\n");

        puts ("end of loop\n");
    }
    return a / b;
}
