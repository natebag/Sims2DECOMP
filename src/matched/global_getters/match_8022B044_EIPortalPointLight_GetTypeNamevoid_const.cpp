// 0x8022B044 (12 bytes)
class EIPortalPointLight {
public:
    const char* GetTypeName() const;
};

extern char gEIPortalPointLightData[];

const char* EIPortalPointLight::GetTypeName() const {
    return *(const char**)(gEIPortalPointLightData + 0);
}
