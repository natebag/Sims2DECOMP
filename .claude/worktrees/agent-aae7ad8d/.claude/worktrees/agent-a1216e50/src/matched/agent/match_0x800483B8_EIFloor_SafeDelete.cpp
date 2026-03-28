/* EIFloor::SafeDelete(void) - 0x800483B8 (64 bytes) */

struct EIFloor {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EIFloor();
    static void SafeDelete(EIFloor *p);
};

void EIFloor::SafeDelete(EIFloor *p)
{
    if (p) {
        delete p;
    }
}
