// FLAGS: -fno-schedule-insns
// 0x802BB4D4 AptXmlNode::sMethod_insertBefore (8B)
// lwz r3,gAptMethodUnimpl(r13) -- unimplemented APT method stub
extern int gAptMethodUnimpl;
extern "C" int f_802BB4D4() { return gAptMethodUnimpl; }
