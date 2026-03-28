/* EFontPage::SafeDelete(void) - 0x8036482C (64 bytes) */

struct EFontPage {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EFontPage();
    static void SafeDelete(EFontPage *p);
};

void EFontPage::SafeDelete(EFontPage *p)
{
    if (p) {
        delete p;
    }
}
