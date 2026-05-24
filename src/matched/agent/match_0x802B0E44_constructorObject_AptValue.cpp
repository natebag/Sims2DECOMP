// FLAGS: -fno-schedule-insns
// 0x802B0E44 _constructorObject (8B)
// lwz r3,gAptMethodUnimpl(r13) -- unimplemented APT method stub
extern int gAptMethodUnimpl;
extern "C" int f_802B0E44() { return gAptMethodUnimpl; }
