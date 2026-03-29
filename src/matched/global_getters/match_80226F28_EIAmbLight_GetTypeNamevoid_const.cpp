// 0x80226F28 (12 bytes)
class EIAmbLight {
public:
    const char* GetTypeName() const;
};

extern char gEIAmbLightData[];

const char* EIAmbLight::GetTypeName() const {
    return *(const char**)(gEIAmbLightData + 0);
}
