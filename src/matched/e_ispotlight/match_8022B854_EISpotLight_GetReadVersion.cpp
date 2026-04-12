// 0x8022B854 (12 bytes)
class EISpotLight {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short EISpotLight_readVersion[];

unsigned short EISpotLight::GetReadVersion() const {
    return EISpotLight_readVersion[0];
}
