void printf (char const *fmt, ...);

void printit (int *pointer)
{
    int i;
    for (i = 0;; i ++) {
        printf ("%2d: %3d\n", i, pointer[i]);
        if (pointer[i] == 99) break;
    }
}

int main()
{
    int arry[] = {
        11, 12,
        21, 22, 23,
        31,
        99 };

    printit (arry);
    return 0;
}
