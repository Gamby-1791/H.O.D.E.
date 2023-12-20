typedef int IntToInt (int x);

int negate (int x)
{
    return -x;
}

int complement (int x)
{
    return ~x;
}

IntToInt increment
{
    return x + 1;
}

IntToInt decrement
{
    return x - 1;
}

IntToInt *funcpointer = complement;

int intarray[10];

int main ()
{
    int total = 0;
    int i;
    int *p = &intarray[3];
    for (i = 3; i < 10; i += 1) {
        total += *(p ++);
    }
    return 0;
}
