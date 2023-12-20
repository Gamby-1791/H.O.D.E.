struct Par {
    int *ptr;
    __uint64_t unum;
};

void test27 (Par *p)
{
    __int64_t snum = *(p->ptr);
    bool neg = (snum < 0);
    p->unum = snum ? - snum : snum;
}
