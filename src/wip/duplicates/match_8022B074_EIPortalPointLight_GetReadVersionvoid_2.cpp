// 0x8022B074 (12 bytes)
class EIPortalPointLight {
public:
    short GetReadVersion() const;
};

extern char gEIPortalPointLightData[];

short EIPortalPointLight::GetReadVersion() const {
    return *(short*)(gEIPortalPointLightData + 0);
}
