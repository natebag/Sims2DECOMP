// 0x80228044 (12 bytes)
class EILight {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short EILight_readVersion[];

unsigned short EILight::GetReadVersion() const {
    return EILight_readVersion[0];
}
