// 0x80226EDC EIAmbLight::SafeDelete (64B)

struct EIAmbLight {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EIAmbLight();
    void SafeDelete();
};

void EIAmbLight::SafeDelete() {
    if (this != 0) {
        delete this;
    }
}
