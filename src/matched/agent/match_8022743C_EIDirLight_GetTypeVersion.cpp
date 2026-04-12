// 0x8022743C (12 bytes)
class EIDirLight {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short EIDirLight_typeInfo_version[];

unsigned short EIDirLight::GetTypeVersion() const {
    return EIDirLight_typeInfo_version[0];
}
