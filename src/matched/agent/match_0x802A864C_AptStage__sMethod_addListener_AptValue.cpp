// FLAGS: -fno-schedule-insns
// 0x802A864C AptStage::sMethod_addListener (8B)
// lwz r3,gAptMethodUnimpl(r13) -- unimplemented APT method stub
extern int gAptMethodUnimpl;
extern "C" int f_802A864C() { return gAptMethodUnimpl; }
