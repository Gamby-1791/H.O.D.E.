struct Token {
    Token *next;            // next token in line
    char const *srcname;    // source file name
    int srcline;            // one-based line in source file
    int srcchar;            // zero-based character in source line
    __uint32_t intval;      // integer value
    char toktype;           // TT_ token type
    char strval[1];         // string value (null terminated)
};

char const *test28 (Token *token)
{
    return token->strval;
}
