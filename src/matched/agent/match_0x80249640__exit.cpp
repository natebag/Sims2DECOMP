// 0x80249640 _exit(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0"
extern "C" void _exit() {}
