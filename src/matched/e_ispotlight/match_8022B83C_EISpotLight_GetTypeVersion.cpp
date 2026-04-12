// 0x8022B83C (12 bytes)
class EISpotLight {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short EISpotLight_typeInfo_version[];

unsigned short EISpotLight::GetTypeVersion() const {
    return EISpotLight_typeInfo_version[0];
}
