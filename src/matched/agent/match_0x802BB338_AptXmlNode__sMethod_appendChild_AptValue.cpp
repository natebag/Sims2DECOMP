// FLAGS: -fno-schedule-insns
// 0x802BB338 AptXmlNode::sMethod_appendChild (8B)
// lwz r3,gAptMethodUnimpl(r13) -- unimplemented APT method stub
extern int gAptMethodUnimpl;
extern "C" int f_802BB338() { return gAptMethodUnimpl; }
