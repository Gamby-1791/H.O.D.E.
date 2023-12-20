typedef int IntToInt (int a);

int increment (int a)
{
    return a + 1;
}

int decrement (int b)
{
    return b - 1;
}

int main (int argc, char **argv)
{
    IntToInt *i2i = increment; //TODO FIX (argc & 1) ? increment : decrement;

    int incd =   i2i  (argc);
    int decd = (*i2i) (argc);

    return incd + decd;
}
