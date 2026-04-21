// 0x803B35DC CasEventStoreSim::Log (44 bytes)
// Printf-thunk template: non-SDA extern char[256] format + CasEventDummyPrintf varargs.

extern char gCasEventStoreSimLogFormat[256];

extern "C" void CasEventDummyPrintf(const char* fmt, ...);

struct CasEventStoreSim {
    void Log() const;
};

void CasEventStoreSim::Log() const {
    CasEventDummyPrintf(gCasEventStoreSimLogFormat);
}
