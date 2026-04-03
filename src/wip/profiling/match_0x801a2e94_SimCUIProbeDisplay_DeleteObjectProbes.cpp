// match_0x801a2e94_SimCUIProbeDisplay_DeleteObjectProbes.cpp
// Release build version (228 bytes)
// Delete all object probes from display

struct ObjectProbe {
};

struct SimCUIProbeDisplay {
    ObjectProbe **m_objectProbes;
    int m_probeCount;
    
    void DeleteObjectProbes() {
        // Iterate and delete each probe
        for (int i = 0; i < m_probeCount; i++) {
            if (m_objectProbes[i]) {
                delete m_objectProbes[i];
                m_objectProbes[i] = 0;
            }
        }
        m_probeCount = 0;
    }
};
