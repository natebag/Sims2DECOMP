/* ERBinary::SafeDelete(void) - 0x80368510 (64 bytes) */

struct ERBinary {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ERBinary();
    static void SafeDelete(ERBinary *p);
};

void ERBinary::SafeDelete(ERBinary *p)
{
    if (p) {
        delete p;
    }
}
