// 0x80226E3C EIAmbLight::New(void) (68B)

class EILight {
public:
    EILight();
    virtual int GetLightType();
};

class EIAmbLight : public EILight {
    char _pad[168];
public:
    inline EIAmbLight() : EILight() {}
    virtual int GetLightType();
    static EIAmbLight* New();
};

EIAmbLight* EIAmbLight::New() {
    EIAmbLight* p = new EIAmbLight;
    return p;
}
