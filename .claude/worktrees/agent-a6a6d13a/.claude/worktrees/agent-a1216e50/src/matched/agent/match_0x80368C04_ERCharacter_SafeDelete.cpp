/* ERCharacter::SafeDelete(void) - 0x80368C04 (64 bytes) */

struct ERCharacter {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ERCharacter();
    static void SafeDelete(ERCharacter *p);
};

void ERCharacter::SafeDelete(ERCharacter *p)
{
    if (p) {
        delete p;
    }
}
