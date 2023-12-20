struct SomeStruct {
    float value;
};

SomeStruct *test33 ()
{
    SomeStruct *s = new SomeStruct;
    s->value = 5;
    return s;
}
