// match_0x801a42a8_SimLoopProbe_dtor.cpp
// Release build version (228 bytes)
// Destructor for SimLoopProbe

struct SimLoopProbe {
    int *m_samples;
    int m_sampleCount;
    
    ~SimLoopProbe() {
        // Clean up sample array
        if (m_samples) {
            delete[] m_samples;
            m_samples = 0;
        }
        m_sampleCount = 0;
    }
};
