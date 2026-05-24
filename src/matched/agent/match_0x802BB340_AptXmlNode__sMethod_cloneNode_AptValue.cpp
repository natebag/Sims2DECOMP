// FLAGS: -fno-schedule-insns
// 0x802BB340 AptXmlNode::sMethod_cloneNode (8B)
// lwz r3,gAptMethodUnimpl(r13) -- unimplemented APT method stub
extern int gAptMethodUnimpl;
extern "C" int f_802BB340() { return gAptMethodUnimpl; }
