// 0x80229C04 EIPointAmbLight::SafeDelete (64B)

struct EIPointAmbLight {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EIPointAmbLight();
    void SafeDelete();
};

void EIPointAmbLight::SafeDelete() {
    if (this != 0) {
        delete this;
    }
}
