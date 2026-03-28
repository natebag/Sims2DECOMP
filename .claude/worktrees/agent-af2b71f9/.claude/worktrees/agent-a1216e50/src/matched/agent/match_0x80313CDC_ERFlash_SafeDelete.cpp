/* ERFlash::SafeDelete(void) - 0x80313CDC (64 bytes) */

struct ERFlash {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ERFlash();
    static void SafeDelete(ERFlash *p);
};

void ERFlash::SafeDelete(ERFlash *p)
{
    if (p) {
        delete p;
    }
}
