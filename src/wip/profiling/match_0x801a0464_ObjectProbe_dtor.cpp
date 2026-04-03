// match_0x801a0464_ObjectProbe_dtor.cpp
// Release build version (260 bytes)
// Destructor for ObjectProbe

struct SimCUIProbeDisplay;

struct ObjectProbe {
    int *m_tickData;
    SimCUIProbeDisplay *m_display;
    int m_dataCount;
    
    ~ObjectProbe() {
        // Clean up tick data array
        if (m_tickData) {
            delete[] m_tickData;
            m_tickData = 0;
        }
        
        // Clean up references
        m_dataCount = 0;
        m_display = 0;
    }
};
