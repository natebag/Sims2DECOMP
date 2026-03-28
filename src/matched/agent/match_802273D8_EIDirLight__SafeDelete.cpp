struct EIDirLight {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual ~EIDirLight();
    void SafeDelete();
};

void EIDirLight::SafeDelete() {
    if (this != 0) {
        delete this;
    }
}
