/* ERFont::SafeDelete(void) - 0x80317808 (64 bytes) */

struct ERFont {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ERFont();
    static void SafeDelete(ERFont *p);
};

void ERFont::SafeDelete(ERFont *p)
{
    if (p) {
        delete p;
    }
}
