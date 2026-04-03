// match_0x801a1764_SimLoopProbe_GetNthSample.cpp
// Release build version (196 bytes)
// Get Nth sample from probe sample array

struct SimTickSample {
    int tickNumber;
    int tickDuration;
};

struct SimLoopProbe {
    SimTickSample *m_samples;
    int m_sampleCount;
    int m_maxSamples;
    
    SimTickSample *GetNthSample(int index) {
        // Array bounds check and return sample pointer
        if (index < 0 || index >= m_sampleCount) {
            return 0;
        }
        return &m_samples[index];
    }
};
