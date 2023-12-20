void puts (char const *str);
void printdouble (double d);

char buf[80];

double whoratio (int a, int b)
{
    int iyi;
    for (iyi = 0; iyi < 10; iyi ++) {
        buf[0] = (char) iyi + '0';
        buf[1] = '\n';
        buf[2] = 0;
        puts (buf);
    }
    double d;
    d = 0.1;
    puts ("hello world\n");
    return a / (double) b;
}

void callwhore ()
{
    double d = whoratio (5, 9);
    printdouble (d);

    printdouble (whoratio (7, 9));
}
