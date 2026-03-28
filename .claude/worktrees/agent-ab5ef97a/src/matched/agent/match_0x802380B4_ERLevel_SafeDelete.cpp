/* ERLevel::SafeDelete(void) - 0x802380B4 (64 bytes) */

struct ERLevel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ERLevel();
    static void SafeDelete(ERLevel *p);
};

void ERLevel::SafeDelete(ERLevel *p)
{
    if (p) {
        delete p;
    }
}
