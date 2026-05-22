// 0x8023EE70 PClseek(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="b pcNotImpl"
extern "C" void pcNotImpl();
extern "C" void PClseek() {}
