// 0x8022B830 (12 bytes)
class EISpotLight {
public:
    const char* GetTypeKey() const;
};

extern char gEISpotLightData[];

const char* EISpotLight::GetTypeKey() const {
    return *(const char**)(gEISpotLightData + 0);
}
