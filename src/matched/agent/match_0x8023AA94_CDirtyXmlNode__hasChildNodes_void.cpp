// 0x8023AA94 CDirtyXmlNode::hasChildNodes(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x10(3); li 3,1; cmplwi 0,0; bgtlr; li 3,0"
extern "C" int f_8023AA94() {}
