struct SomeStruct {
    int intmema;
    int intmemb;
    char const strmem[20];
};

SomeStruct *firststruct;
SomeStruct **laststruct = &firststruct;

char const *staticstringpointer = "static string constant";

int anarray[10];
int *apointer = anarray + 7;
int *bpointer = &anarray[3];

int adiff = &anarray[7] - &anarray[4];

int somefunc ()
{
    char stringinit[6] = "abc";

    int arrayinit[10] = { [0] = 99, [5] = 10, 11, [7] = 14, [3] = 6 };

    SomeStruct somestr = { .intmemb = 22, .intmema = 11, .strmem = "struct string" };

    int i, j;
    for (i = 0; i < 10; i ++) {
        j = arrayinit[i];
    }

    return stringinit[0];
}
