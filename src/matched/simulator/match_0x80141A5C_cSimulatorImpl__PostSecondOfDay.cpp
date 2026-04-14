// cSimulatorImpl::PostSecondOfDay(int) at 0x80141A5C (40B)

struct cSim_PSOD {
    char pad_00[0x14];
    short m_hour;         // at 0x14
    char pad_16[0x1E-0x16];
    short m_min;          // at 0x1E
    short m_sec;          // at 0x20
    char pad_22[0x80-0x22];
    int m_diff;           // at 0x80
    void PostSecondOfDay(int arg);
};

void cSim_PSOD::PostSecondOfDay(int arg) {
    int total = m_sec + m_min * 60 + m_hour * 3600;
    m_diff = arg - total;
}
