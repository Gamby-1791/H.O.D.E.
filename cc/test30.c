typedef int Callback (void *param);

struct Par {
    int spacer;
    Callback *entry;
    void *param;
    int sts;
};

void test30 (Par *p)
{
    p->sts = (*(p->entry)) (p->param);
}
