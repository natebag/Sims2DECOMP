// 0x801A00BC (80 bytes)
// AvgIntervalProbe::Flush(void)

struct AvgIntervalProbe {
    unsigned int m_numSamples;
    unsigned long long m_total;
    unsigned int m_min;
    unsigned int m_max;
    
    void Flush(void) {
        m_numSamples = 0;
        m_total = 0;
        m_min = 0xFFFFFFFF;
        m_max = 0;
    }
};
