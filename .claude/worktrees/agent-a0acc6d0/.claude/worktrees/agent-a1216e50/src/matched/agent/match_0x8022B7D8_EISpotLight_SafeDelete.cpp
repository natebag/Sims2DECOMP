/* EISpotLight::SafeDelete(void) - 0x8022B7D8 (64 bytes) */

struct EISpotLight {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EISpotLight();
    static void SafeDelete(EISpotLight *p);
};

void EISpotLight::SafeDelete(EISpotLight *p)
{
    if (p) {
        delete p;
    }
}
