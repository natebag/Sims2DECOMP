// 0x8022A59C (12 bytes)
class EIPointLight {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short EIPointLight_readVersion[];

unsigned short EIPointLight::GetReadVersion() const {
    return EIPointLight_readVersion[0];
}
