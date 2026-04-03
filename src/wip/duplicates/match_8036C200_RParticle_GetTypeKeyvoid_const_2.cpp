// 0x8036C200 (12 bytes)
class RParticle {
public:
    const char* GetTypeKey() const;
};

extern char gRParticleData[];

const char* RParticle::GetTypeKey() const {
    return *(const char**)(gRParticleData + 0);
}
