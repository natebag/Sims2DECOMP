// 0x803B0EEC CasEventResetSimDraw::Log (64 bytes)
// Printf-thunk template + bool(field != 0).

extern char gCasEventResetSimDrawLogFormat[256];

extern "C" void CasEventDummyPrintf(const char* fmt, ...);

struct CasEventResetSimDraw {
    char pad[8];
    int m_field8;
    void Log() const;
};

void CasEventResetSimDraw::Log() const {
    int v = 0;
    if (m_field8 != 0) v = 1;
    CasEventDummyPrintf(gCasEventResetSimDrawLogFormat, v);
}
