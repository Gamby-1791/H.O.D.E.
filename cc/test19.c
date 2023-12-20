struct Test {
    int a;
    int b;
};

int test19 (Test *one, Test two)
{
    one->a = two.a + 5;
    two.b = one->b * 8;
}
