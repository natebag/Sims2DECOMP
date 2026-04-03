// 0x801A3070 (100 bytes)
// SimCUIProbeDisplay::GetObjectProbe(short)

class ObjectProbe;

struct SimCUIProbeDisplay {
    ObjectProbe** m_probes;
    unsigned int m_probeCount;
    
    ObjectProbe* GetObjectProbe(short idx) {
        if (!m_probes || idx < 0 || idx >= (short)m_probeCount) {
            return 0;
        }
        return m_probes[idx];
    }
};
