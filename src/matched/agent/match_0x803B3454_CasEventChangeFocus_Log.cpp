// 0x803B3454 CasEventChangeFocus::Log (48 bytes)
// DOL:
//   prologue (stwu/mflr/stw)
//   lwz r4, 8(r3)                 ; load m_field8
//   lis r3, hi(format) ; addi r3, r3, lo(format)
//   crclr 4*cr1+eq                ; varargs marker
//   bl CasEventDummyPrintf
//   epilogue

extern char gCasEventChangeFocusLogFormat[256];

extern "C" void CasEventDummyPrintf(const char* fmt, ...);

struct CasEventChangeFocus {
    char pad[8];
    int m_field8;
};

extern "C" void CasEventChangeFocus_Log(CasEventChangeFocus* this_) {
    CasEventDummyPrintf(gCasEventChangeFocusLogFormat, this_->m_field8);
}
