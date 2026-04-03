// match_0x801a2f78_SimCUIProbeDisplay_PauseObjectProbes.cpp
// Release build version (248 bytes)
// Pause all object probes in display

struct ObjectProbe {
    bool m_paused;
};

struct SimCUIProbeDisplay {
    ObjectProbe **m_objectProbes;
    int m_probeCount;
    
    void PauseObjectProbes() {
        // Mark all probes as paused
        for (int i = 0; i < m_probeCount; i++) {
            if (m_objectProbes[i]) {
                m_objectProbes[i]->m_paused = true;
            }
        }
    }
};
