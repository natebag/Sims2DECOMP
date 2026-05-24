// FLAGS: -fno-schedule-insns
// 0x802A8654 AptStage::sMethod_removeListener (8B)
// lwz r3,gAptMethodUnimpl(r13) -- unimplemented APT method stub
extern int gAptMethodUnimpl;
extern "C" int f_802A8654() { return gAptMethodUnimpl; }
