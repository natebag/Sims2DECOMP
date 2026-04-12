// 0x8022A584 (12 bytes)
class EIPointLight {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short EIPointLight_typeInfo_version[];

unsigned short EIPointLight::GetTypeVersion() const {
    return EIPointLight_typeInfo_version[0];
}
