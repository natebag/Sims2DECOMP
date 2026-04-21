// 0x803B0E14 CasEventChangeSimS2C::Log (64 bytes)
// DOL: prologue; mr r9,r3; lis r3,fmt; lwz r7,20(r9); lwz r4,8(r9);
//       addi r3,fmt_lo; lwz r5,12(r9); lwz r6,16(r9); crclr; bl printf; epilogue.

extern char gCasEventChangeSimS2CLogFormat[256];

extern "C" void CasEventDummyPrintf(const char* fmt, ...);

struct CasEventChangeSimS2C {
    char pad[8];
    int m_field8;
    int m_field12;
    int m_field16;
    int m_field20;
};

extern "C" void CasEventChangeSimS2C_Log(CasEventChangeSimS2C* this_) {
    CasEventDummyPrintf(gCasEventChangeSimS2CLogFormat,
        this_->m_field8, this_->m_field12, this_->m_field16, this_->m_field20);
}
