// 0x80229C80 (12 bytes)
class EIPointAmbLight {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short EIPointAmbLight_readVersion[];

unsigned short EIPointAmbLight::GetReadVersion() const {
    return EIPointAmbLight_readVersion[0];
}
