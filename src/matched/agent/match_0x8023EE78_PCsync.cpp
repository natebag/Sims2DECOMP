// 0x8023EE78 PCsync(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="b pcNotImpl"
extern "C" void pcNotImpl();
extern "C" void PCsync() {}
