// 0x80227FC8 EILight::SafeDelete (64B)

struct EILight {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EILight();
    void SafeDelete();
};

void EILight::SafeDelete() {
    if (this != 0) {
        delete this;
    }
}
