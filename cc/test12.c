typedef __uint16_t uint16_t;

typedef struct Opcode Opcode;
typedef struct PSect PSect;
typedef struct Stack Stack;
typedef struct Symbol Symbol;
typedef struct Token Token;

struct PSect {
    PSect *next;            // next in psects list
    uint16_t p2al;          // log2 power of alignment
    uint16_t base;          // section base address
    uint16_t offs;          // offset for next object code generation
    uint16_t size;          // total size of the section
    char name[1];           // null terminated psect name
};

extern void *malloc (uint16_t size);

int main (int argc, char **argv)
{
    char const *asmname, *hexname;
    PSect *psect, *textpsect;
    uint16_t base, mask;

    if (argc != 3) {
        return 1;
    }

    asmname = argv[1];

    textpsect = (PSect *) malloc (5 + sizeof *textpsect);

    return 0;
}
