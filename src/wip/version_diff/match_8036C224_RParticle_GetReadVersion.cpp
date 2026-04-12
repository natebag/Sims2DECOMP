// 0x8036C224 (12 bytes)
class RParticle {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short RParticle_readVersion[];

unsigned short RParticle::GetReadVersion() const {
    return RParticle_readVersion[0];
}
