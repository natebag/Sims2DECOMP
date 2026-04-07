// 0x803B0D68 CasEventInitSim::Log (48 bytes)
// DOL:
//   prologue (stwu/mflr/stw)
//   lwz r4, 140(r3)               ; load m_field
//   lis r3, hi(format) ; addi r3, r3, lo(format)   ; non-SDA addr
//   crclr 4*cr1+eq                ; varargs marker
//   bl printf
//   epilogue
// Non-SDA via large array forces lis+addi pair.

extern char gCasEventLogFormat[256];

extern "C" void CasEventDummyPrintf(const char* fmt, ...);

struct CasEventInitSim {
    char pad[140];
    int m_field8C;  // offset 140
};

extern "C" void CasEventInitSim_Log(CasEventInitSim* this_) {
    CasEventDummyPrintf(gCasEventLogFormat, this_->m_field8C);
}
