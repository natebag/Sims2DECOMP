/* 0x8005c87c (104 bytes) - SAnimator2::checkParticleCleanup(void) */
class SAnimator2 {
public:
    char pad[0x61C];
    int m_stateFlags;
    void cleanupParticlesDelayed(void* tree);
    void checkParticleCleanup(void);
};

void SAnimator2::checkParticleCleanup() {
    if (m_stateFlags & 0x10000) {
        cleanupParticlesDelayed((char*)this + 0x5D0);
        m_stateFlags &= ~0x10000;
    }
    if (m_stateFlags & 0x20000) {
        cleanupParticlesDelayed((char*)this + 0x5DC);
        m_stateFlags &= ~0x20000;
    }
}
