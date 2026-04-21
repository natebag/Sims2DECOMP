// 0x803B0E14 CasEventChangeSimS2C::Log (64 bytes)
// Printf-thunk template + 4 int fields.

extern char gCasEventChangeSimS2CLogFormat[256];

extern "C" void CasEventDummyPrintf(const char* fmt, ...);

struct CasEventChangeSimS2C {
    char pad[8];
    int m_field8;
    int m_field12;
    int m_field16;
    int m_field20;
    void Log() const;
};

void CasEventChangeSimS2C::Log() const {
    CasEventDummyPrintf(gCasEventChangeSimS2CLogFormat,
        m_field8, m_field12, m_field16, m_field20);
}
