// 0x8022B050 (12 bytes)
class EIPortalPointLight {
public:
    const char* GetTypeKey() const;
};

extern char gEIPortalPointLightData[];

const char* EIPortalPointLight::GetTypeKey() const {
    return *(const char**)(gEIPortalPointLightData + 0);
}
