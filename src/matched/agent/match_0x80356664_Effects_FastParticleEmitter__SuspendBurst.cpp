// 0x80356664 (28B) Effects::FastParticleEmitter::SuspendBurst(void)
struct FPE_Inner { char pad[0x14]; float m_14; };
struct FPE_SB {
    char pad1[0x148];
    unsigned int m_148;
    char pad2[0xC];
    float m_158;
    char pad3[0x30];
    FPE_Inner* m_18C;
    void SuspendBurst();
};
void FPE_SB::SuspendBurst() {
    m_148 |= 0x800u;
    m_158 = m_18C->m_14;
}
