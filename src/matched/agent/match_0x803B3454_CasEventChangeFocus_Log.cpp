// 0x803B3454 CasEventChangeFocus::Log (48 bytes)
// Printf-thunk template + 1 int field.

extern char gCasEventChangeFocusLogFormat[256];

extern "C" void CasEventDummyPrintf(const char* fmt, ...);

struct CasEventChangeFocus {
    char pad[8];
    int m_field8;
    void Log() const;
};

void CasEventChangeFocus::Log() const {
    CasEventDummyPrintf(gCasEventChangeFocusLogFormat, m_field8);
}
