// 0x803B35DC CasEventStoreSim::Log (44 bytes)
// DOL:
//   prologue (stwu/mflr/stw)
//   lis r3, hi(format) ; addi r3, r3, lo(format)   ; non-SDA addr
//   crclr 4*cr1+eq                ; varargs marker
//   bl CasEventDummyPrintf
//   epilogue

extern char gCasEventStoreSimLogFormat[256];

extern "C" void CasEventDummyPrintf(const char* fmt, ...);

struct CasEventStoreSim;

extern "C" void CasEventStoreSim_Log(CasEventStoreSim* this_) {
    CasEventDummyPrintf(gCasEventStoreSimLogFormat);
}
