// 0x803B0E84 CasEventMorphSimS2C::Log (56 bytes)
// DOL: prologue; mr r9,r3; lfs f1,12(r9); lis/addi r3,format; lwz r4,8(r9);
//       crset 4*cr1+eq (varargs has FP); bl printf; epilogue.

extern char gCasEventMorphSimS2CLogFormat[256];

extern "C" void CasEventDummyPrintf(const char* fmt, ...);

struct CasEventMorphSimS2C {
    char pad[8];
    int m_field8;
    float m_field12;
};

extern "C" void CasEventMorphSimS2C_Log(CasEventMorphSimS2C* this_) {
    CasEventDummyPrintf(gCasEventMorphSimS2CLogFormat, this_->m_field8, this_->m_field12);
}
