// 0x8036C1F4 (12 bytes)
class RParticle {
public:
    const char* GetTypeName() const;
};

extern char gRParticleData[];

const char* RParticle::GetTypeName() const {
    return *(const char**)(gRParticleData + 0);
}
