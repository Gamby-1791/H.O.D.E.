int somefunc ()
{
    int i = 5, j = 7, k = i + j;
    i += 4;
    int m = k ++;
    int n = -- j;
    return m | n;
}
