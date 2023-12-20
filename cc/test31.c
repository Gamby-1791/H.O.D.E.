struct Ex {
    int a;
};

struct REx : Ex {
    int b;
};

struct NPEx : REx {
    int c;
};

void putint (int val);
void putstr (char const *str);

void test31 ()
{
    try {
        putstr ("try block");
        throw "something thrown";
    } catch (NPEx *ne) {
        putstr ("exception NPEx");
        putstr ((char const *) ne);
    } catch (Ex *e, void const *const *t) {
        putstr ("exception Ex");
        putstr ((char const *) e);
        putstr ((char const *) t[0]);
        throw;
    } finally {
        putstr ("finally block");
    }
}
