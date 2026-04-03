// 0x801A010C (160 bytes)
// AvgIntervalProbe::GetAvg(void)

struct AvgIntervalProbe {
    unsigned int m_numSamples;
    unsigned long long m_total;
    unsigned int m_minVal;
    unsigned int m_maxVal;
    double m_lastAvg;
    
    double GetAvg(void) {
        if (m_numSamples == 0) {
            return 0.0;
        }
        
        // Calculate average
        unsigned long long avg = m_total / (unsigned long long)m_numSamples;
        m_lastAvg = (double)avg;
        
        return m_lastAvg;
    }
};
