char stringinit[30] = "some string init";

int arrayinit[10] = { [5] = 10, 11, [7] = 14, [3] = 6 };


struct SomeStruct {
    int intmema;
    int intmemb;
    char const strmem[20];
};

SomeStruct somestr = { .intmemb = 22, .intmema = 11, .strmem = "struct string" };

