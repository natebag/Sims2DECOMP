/* EFontData::SafeDelete(void) - 0x80364AFC (64 bytes) */

struct EFontData {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EFontData();
    static void SafeDelete(EFontData *p);
};

void EFontData::SafeDelete(EFontData *p)
{
    if (p) {
        delete p;
    }
}
