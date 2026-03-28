// 0x80356654 (8 bytes)
class Effects {
public:
    class FastParticleEmitter {
    public:
        float GetAlphaScale();
    };
};

float Effects::FastParticleEmitter::GetAlphaScale() {
    return *(float*)((char*)this + 0x14C);
}
