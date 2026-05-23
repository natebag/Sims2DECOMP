namespace Effects {
struct FastParticleEmitter {
    char _pad[0x14c];
    float m_alphaScale;
    float GetAlphaScale();
};
}
float Effects::FastParticleEmitter::GetAlphaScale() { return m_alphaScale; }
