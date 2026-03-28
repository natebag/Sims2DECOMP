/* EFontSize::SafeDelete(void) - 0x80364994 (64 bytes) */

struct EFontSize {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EFontSize();
    static void SafeDelete(EFontSize *p);
};

void EFontSize::SafeDelete(EFontSize *p)
{
    if (p) {
        delete p;
    }
}
