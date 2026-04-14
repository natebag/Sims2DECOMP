// 0x8022AFF8 EIPortalPointLight::SafeDelete (64B)

struct EIPortalPointLight {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EIPortalPointLight();
    void SafeDelete();
};

void EIPortalPointLight::SafeDelete() {
    if (this != 0) {
        delete this;
    }
}
