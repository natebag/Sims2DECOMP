// 0x8022B824 (12 bytes)
class EISpotLight {
public:
    const char* GetTypeName() const;
};

extern char gEISpotLightData[];

const char* EISpotLight::GetTypeName() const {
    return *(const char**)(gEISpotLightData + 0);
}
