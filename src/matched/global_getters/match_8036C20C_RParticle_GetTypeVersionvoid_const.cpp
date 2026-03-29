// 0x8036C20C (12 bytes)
class RParticle {
public:
    short GetTypeVersion() const;
};

extern char gRParticleData[];

short RParticle::GetTypeVersion() const {
    return *(short*)(gRParticleData + 0);
}
