// 0x80226F58 (12 bytes)
class EIAmbLight {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short EIAmbLight_readVersion[];

unsigned short EIAmbLight::GetReadVersion() const {
    return EIAmbLight_readVersion[0];
}
