/* EIPortalPointLight::SafeDelete(void) - 0x8022AFF8 (64 bytes) */

struct EIPortalPointLight {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EIPortalPointLight();
    static void SafeDelete(EIPortalPointLight *p);
};

void EIPortalPointLight::SafeDelete(EIPortalPointLight *p)
{
    if (p) {
        delete p;
    }
}
