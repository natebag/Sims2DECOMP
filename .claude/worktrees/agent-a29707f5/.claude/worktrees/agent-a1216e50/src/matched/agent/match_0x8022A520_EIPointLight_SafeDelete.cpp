/* EIPointLight::SafeDelete(void) - 0x8022A520 (64 bytes) */

struct EIPointLight {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EIPointLight();
    static void SafeDelete(EIPointLight *p);
};

void EIPointLight::SafeDelete(EIPointLight *p)
{
    if (p) {
        delete p;
    }
}
