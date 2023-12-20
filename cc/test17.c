char test17 (int a)
{
    __uint64_t unsignednum = a;
    char digit = (char) (unsignednum % 10) + '0';
    return digit;
}
