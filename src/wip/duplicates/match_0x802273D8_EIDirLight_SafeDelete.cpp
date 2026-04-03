/* EIDirLight::SafeDelete(void) - 0x802273D8 (64 bytes) */

struct EIDirLight {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EIDirLight();
    static void SafeDelete(EIDirLight *p);
};

void EIDirLight::SafeDelete(EIDirLight *p)
{
    if (p) {
        delete p;
    }
}
