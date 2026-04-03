// 0x80226F34 (12 bytes)
class EIAmbLight {
public:
    const char* GetTypeKey() const;
};

extern char gEIAmbLightData[];

const char* EIAmbLight::GetTypeKey() const {
    return *(const char**)(gEIAmbLightData + 0);
}
