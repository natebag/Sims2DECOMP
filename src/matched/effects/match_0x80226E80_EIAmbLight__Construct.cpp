// 0x80226E80 EIAmbLight::Construct(EIAmbLight*) (56B)

inline void* operator new(unsigned, void* p) { return p; }

class EILight {
public:
    EILight();
    virtual int GetLightType();
};

class EIAmbLight : public EILight {
public:
    inline EIAmbLight() : EILight() {}
    virtual int GetLightType();
    static void Construct(EIAmbLight* obj);
};

void EIAmbLight::Construct(EIAmbLight* obj) {
    new(obj) EIAmbLight;
}
