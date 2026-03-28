/* EFontCharacter::SafeDelete(void) - 0x803646D8 (64 bytes) */

struct EFontCharacter {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EFontCharacter();
    static void SafeDelete(EFontCharacter *p);
};

void EFontCharacter::SafeDelete(EFontCharacter *p)
{
    if (p) {
        delete p;
    }
}
