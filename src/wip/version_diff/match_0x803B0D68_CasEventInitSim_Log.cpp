// CasEventInitSim::Log(void) const
// Address: 0x803B0D68 | Size: 48 bytes
// Pattern: Loads field at offset 140, passes format string and field to printf

struct CasEventInitSim {
    char pad[140];
    int m_field8C;  // at offset 140 (0x8C)
};

// Format string at 0x803EF3B4
extern char gCasEventLogFormat[4];

// Forward declaration
extern "C" void CasEventDummyPrintf(const char* fmt, ...);

extern "C" void CasEventInitSim_Log(CasEventInitSim* this_) {
    CasEventDummyPrintf(gCasEventLogFormat, this_->m_field8C);
}
