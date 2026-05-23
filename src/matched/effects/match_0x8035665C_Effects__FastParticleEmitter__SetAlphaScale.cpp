namespace Effects {
struct FastParticleEmitter {
    char _pad[0x14c];
    float m_alphaScale;
    void SetAlphaScale(float val);
};
}
void Effects::FastParticleEmitter::SetAlphaScale(float val) { m_alphaScale = val; }
