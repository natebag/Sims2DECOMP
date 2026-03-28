/* EIPointAmbLight::SafeDelete(void) - 0x80229C04 (64 bytes) */

struct EIPointAmbLight {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EIPointAmbLight();
    static void SafeDelete(EIPointAmbLight *p);
};

void EIPointAmbLight::SafeDelete(EIPointAmbLight *p)
{
    if (p) {
        delete p;
    }
}
