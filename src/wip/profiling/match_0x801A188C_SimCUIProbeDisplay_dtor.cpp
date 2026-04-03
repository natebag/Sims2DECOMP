// 0x801A188C (84 bytes)
// SimCUIProbeDisplay::~SimCUIProbeDisplay(void)

class ObjectProbe;

struct SimCUIProbeDisplay {
    ObjectProbe** m_probes;
    unsigned int m_probeCount;
    
    ~SimCUIProbeDisplay(void) {
        if (m_probes) {
            for (unsigned int i = 0; i < m_probeCount; i++) {
                if (m_probes[i]) {
                    delete m_probes[i];
                }
            }
            delete[] m_probes;
            m_probes = 0;
        }
        m_probeCount = 0;
    }
};
