void *malloc (__size_t size);

void *__malloc2 (__size_t nmemb, __size_t size)
{
    void *ptr = malloc (size);
    ((__size_t *)ptr)[-1] = nmemb;
    return ptr;
}
