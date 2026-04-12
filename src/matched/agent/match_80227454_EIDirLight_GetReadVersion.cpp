// 0x80227454 (12 bytes)
class EIDirLight {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short EIDirLight_readVersion[];

unsigned short EIDirLight::GetReadVersion() const {
    return EIDirLight_readVersion[0];
}
