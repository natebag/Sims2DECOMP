// 0x8022B05C (12 bytes)
class EIPortalPointLight {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short EIPortalPointLight_typeInfo_version[];

unsigned short EIPortalPointLight::GetTypeVersion() const {
    return EIPortalPointLight_typeInfo_version[0];
}
