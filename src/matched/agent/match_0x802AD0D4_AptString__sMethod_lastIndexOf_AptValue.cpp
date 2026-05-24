// FLAGS: -fno-schedule-insns
// 0x802AD0D4 AptString::sMethod_lastIndexOf (8B)
// lwz r3,gAptMethodUnimpl(r13) -- unimplemented APT method stub
extern int gAptMethodUnimpl;
extern "C" int f_802AD0D4() { return gAptMethodUnimpl; }
