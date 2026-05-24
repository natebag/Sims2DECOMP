// FLAGS: -fno-schedule-insns
// 0x802ABB50 AptSound::sMethod_stop (8B)
// lwz r3,gAptMethodUnimpl(r13) -- unimplemented APT method stub
extern int gAptMethodUnimpl;
extern "C" int f_802ABB50() { return gAptMethodUnimpl; }
