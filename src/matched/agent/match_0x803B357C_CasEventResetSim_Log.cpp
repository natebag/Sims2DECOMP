// 0x803B357C CasEventResetSim::Log (48 bytes)
// Printf-thunk template + 1 int field.

extern char gCasEventResetSimLogFormat[256];

extern "C" void CasEventDummyPrintf(const char* fmt, ...);

struct CasEventResetSim {
    char pad[8];
    int m_field8;
    void Log() const;
};

void CasEventResetSim::Log() const {
    CasEventDummyPrintf(gCasEventResetSimLogFormat, m_field8);
}
