// 0x8022802C (12 bytes)
class EILight {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short EILight_typeInfo_version[];

unsigned short EILight::GetTypeVersion() const {
    return EILight_typeInfo_version[0];
}
