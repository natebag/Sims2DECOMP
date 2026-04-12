// 0x80226F40 (12 bytes)
class EIAmbLight {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short EIAmbLight_typeInfo_version[];

unsigned short EIAmbLight::GetTypeVersion() const {
    return EIAmbLight_typeInfo_version[0];
}
