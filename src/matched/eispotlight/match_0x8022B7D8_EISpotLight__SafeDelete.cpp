// 0x8022B7D8 EISpotLight::SafeDelete (64B)

struct EISpotLight {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EISpotLight();
    void SafeDelete();
};

void EISpotLight::SafeDelete() {
    if (this != 0) {
        delete this;
    }
}
