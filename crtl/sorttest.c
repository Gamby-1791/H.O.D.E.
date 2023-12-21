#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void testcase (int *array, int nelem);
static int compints (void const *a, void const *b);

int main (int argc, char **argv)
{
    int t1[] = { 454,577,788,43,90,632,457,864,23,863 };
    testcase (t1, 10);
    int t2[] = { 4,4,4,4,4 };
    testcase (t2, 5);
    int t3[] = { 1,2,3,4,5 };
    testcase (t3, 5);
    int t4[] = { 5,4,3,2,1 };
    testcase (t4, 5);
    return 0;
}

static void testcase (int *array, int nelem)
{
    qsort (array, nelem, sizeof *array, compints);
    for (int i = 0; i < nelem; i ++) {
        printf (" %d", array[i]);
    }
    printf ("\n");
    for (int i = 0; i < nelem - 1; i ++) {
        assert (array[i] <= array[i+1]);
    }
}

static int compints (void const *a, void const *b)
{
    return *(int *)a - *(int *)b;
}
