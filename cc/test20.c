struct Mcb {
    char *buff;
    int size;
    int used;
};

int test20 (Mcb *mcb)
{
    return -- (mcb -> size);
}
