/* EILight::SafeDelete(void) - 0x80227FC8 (64 bytes) */

struct EILight {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EILight();
    static void SafeDelete(EILight *p);
};

void EILight::SafeDelete(EILight *p)
{
    if (p) {
        delete p;
    }
}
