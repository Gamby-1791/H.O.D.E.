void puts (char const *msg);

struct Blob {
    __int32_t someint;
    char      somechar;
    __int16_t someshorts[12];
    Blob     *nextinlist;
};

int whoratio (int a, int b)
{
    puts ("hello world\n");

    Blob blobvar;

    blobvar.somechar = (char) a;
    blobvar.someshorts[1] = b;

    Blob *blobptr;

    blobptr = &blobvar;

    __int32_t  a = blobvar.someint;
    __int8_t   b = blobvar.somechar;
    __int16_t *c = blobvar.someshorts;
    __int16_t  d = blobvar.someshorts[3];
    Blob      *e = blobvar.nextinlist;

    __int32_t  f = blobptr->someint;
    __int8_t   g = blobptr->somechar;
    __int16_t *h = blobptr->someshorts;
    __int16_t  i = blobptr->someshorts[3];
    Blob      *j = blobptr->nextinlist;

    return blobvar.somechar;
}
