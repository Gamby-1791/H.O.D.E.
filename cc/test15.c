void printint (int val);

extern int abc;

int abc;

int testalign ()
{
    return alignof abc;
}

int testblockexp (int a, int b, int c)
{
    return ({
        printint (a);
        if (b > c) {
            printint (b);
        } else {
            printint (c);
        }
        a + b + c;
    });
}

