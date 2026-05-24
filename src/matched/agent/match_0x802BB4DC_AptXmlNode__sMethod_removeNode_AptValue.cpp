// FLAGS: -fno-schedule-insns
// 0x802BB4DC AptXmlNode::sMethod_removeNode (8B)
// lwz r3,gAptMethodUnimpl(r13) -- unimplemented APT method stub
extern int gAptMethodUnimpl;
extern "C" int f_802BB4DC() { return gAptMethodUnimpl; }
