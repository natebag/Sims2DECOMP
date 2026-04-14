/* EIWallPart::SafeDelete(void) - 0x80030520 (64 bytes) */

struct EIWallPart {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EIWallPart();
    static void SafeDelete(EIWallPart *p);
};

void EIWallPart::SafeDelete(EIWallPart *p)
{
    if (p) {
        delete p;
    }
}
