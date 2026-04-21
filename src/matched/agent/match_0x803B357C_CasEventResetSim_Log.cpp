// 0x803B357C CasEventResetSim::Log (48 bytes)
// DOL:
//   prologue (stwu/mflr/stw)
//   lwz r4, 8(r3)                 ; load m_field8
//   lis r3, hi(format) ; addi r3, r3, lo(format)
//   crclr 4*cr1+eq                ; varargs marker
//   bl CasEventDummyPrintf
//   epilogue

extern char gCasEventResetSimLogFormat[256];

extern "C" void CasEventDummyPrintf(const char* fmt, ...);

struct CasEventResetSim {
    char pad[8];
    int m_field8;
};

extern "C" void CasEventResetSim_Log(CasEventResetSim* this_) {
    CasEventDummyPrintf(gCasEventResetSimLogFormat, this_->m_field8);
}
