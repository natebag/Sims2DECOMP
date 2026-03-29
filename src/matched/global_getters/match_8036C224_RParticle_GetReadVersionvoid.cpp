// 0x8036C224 (12 bytes)
class RParticle {
public:
    short GetReadVersion() const;
};

extern char gRParticleData[];

short RParticle::GetReadVersion() const {
    return *(short*)(gRParticleData + 0);
}
