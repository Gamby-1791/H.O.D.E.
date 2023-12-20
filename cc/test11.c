void sortarray ()
{
    int array[10] = { 5, 3, 5, 23, 5, 34, 6, 4, 98, 32 };

    int top = 10;
    int i;
    while (-- top > 0) {
        for (i = 0; i < top; i ++) {
            int a = array[i];
            int b = array[i+1];
            if (a > b) {
                array[i] = b;
                array[i+1] = a;
            }
        }
    }
}
