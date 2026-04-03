// 0x8035665C (8 bytes)
class Effects {
public:
    class FastParticleEmitter {
    public:
        void SetAlphaScale(float p);
    };
};

void Effects::FastParticleEmitter::SetAlphaScale(float p) {
    *(float*)((char*)this + 0x14C) = p;
}
