// 0x8022B074 (12 bytes)
class EIPortalPointLight {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short EIPortalPointLight_readVersion[];

unsigned short EIPortalPointLight::GetReadVersion() const {
    return EIPortalPointLight_readVersion[0];
}
