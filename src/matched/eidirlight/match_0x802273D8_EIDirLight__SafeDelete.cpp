// 0x802273D8 EIDirLight::SafeDelete (64B)

struct EIDirLight {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EIDirLight();
    void SafeDelete();
};

void EIDirLight::SafeDelete() {
    if (this != 0) {
        delete this;
    }
}
