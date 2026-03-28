/* ESim::SafeDelete(void) - 0x800350B0 (64 bytes) */

struct ESim {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ESim();
    static void SafeDelete(ESim *p);
};

void ESim::SafeDelete(ESim *p)
{
    if (p) {
        delete p;
    }
}
