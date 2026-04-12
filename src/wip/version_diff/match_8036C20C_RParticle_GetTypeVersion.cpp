// 0x8036C20C (12 bytes)
class RParticle {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short RParticle_typeInfo_version[];

unsigned short RParticle::GetTypeVersion() const {
    return RParticle_typeInfo_version[0];
}
