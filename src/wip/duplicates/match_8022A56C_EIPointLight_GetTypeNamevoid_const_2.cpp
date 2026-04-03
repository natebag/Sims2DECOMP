// 0x8022A56C (12 bytes)
class EIPointLight {
public:
    const char* GetTypeName() const;
};

extern char gEIPointLightData[];

const char* EIPointLight::GetTypeName() const {
    return *(const char**)(gEIPointLightData + 0);
}
