// 0x801A13C0 (80 bytes)
// SimLoopProbe::EndSim(void)

struct SimLoopProbe {
    unsigned int m_frameCount;
    unsigned int m_inFrame;
    unsigned long long m_lastTime;
    
    void EndSim(void) {
        if (m_inFrame) {
            m_inFrame = 0;
            m_frameCount++;
        }
    }
};
