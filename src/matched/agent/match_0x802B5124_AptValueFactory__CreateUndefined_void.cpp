// FLAGS: -fno-schedule-insns
// 0x802B5124 AptValueFactory::CreateUndefined (8B)
// lwz r3,gAptMethodUnimpl(r13) -- unimplemented APT method stub
extern int gAptMethodUnimpl;
extern "C" int f_802B5124() { return gAptMethodUnimpl; }
