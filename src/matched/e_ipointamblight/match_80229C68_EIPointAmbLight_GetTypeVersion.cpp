// 0x80229C68 (12 bytes)
class EIPointAmbLight {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short EIPointAmbLight_typeInfo_version[];

unsigned short EIPointAmbLight::GetTypeVersion() const {
    return EIPointAmbLight_typeInfo_version[0];
}
