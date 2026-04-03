// 0x801A01C4 (72 bytes)
// SimTickSample::SimTickSample(void)

struct SimTickSample {
    unsigned long long m_startTick;
    unsigned long long m_endTick;
    unsigned int m_instrs;
    
    SimTickSample(void) {
        m_startTick = 0;
        m_endTick = 0;
        m_instrs = 0;
    }
};
