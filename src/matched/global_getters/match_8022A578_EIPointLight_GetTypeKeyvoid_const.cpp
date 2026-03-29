// 0x8022A578 (12 bytes)
class EIPointLight {
public:
    const char* GetTypeKey() const;
};

extern char gEIPointLightData[];

const char* EIPointLight::GetTypeKey() const {
    return *(const char**)(gEIPointLightData + 0);
}
