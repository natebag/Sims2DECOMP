// 0x8022A520 EIPointLight::SafeDelete (64B)

struct EIPointLight {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EIPointLight();
    void SafeDelete();
};

void EIPointLight::SafeDelete() {
    if (this != 0) {
        delete this;
    }
}
