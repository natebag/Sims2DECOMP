// 0x8022B05C (12 bytes)
class EIPortalPointLight {
public:
    short GetTypeVersion() const;
};

extern char gEIPortalPointLightData[];

short EIPortalPointLight::GetTypeVersion() const {
    return *(short*)(gEIPortalPointLightData + 0);
}
