// 0x803B0E84 CasEventMorphSimS2C::Log (56 bytes)
// Printf-thunk template + int + float (crset cr1+eq for FP in varargs).

extern char gCasEventMorphSimS2CLogFormat[256];

extern "C" void CasEventDummyPrintf(const char* fmt, ...);

struct CasEventMorphSimS2C {
    char pad[8];
    int m_field8;
    float m_field12;
    void Log() const;
};

void CasEventMorphSimS2C::Log() const {
    CasEventDummyPrintf(gCasEventMorphSimS2CLogFormat, m_field8, m_field12);
}
