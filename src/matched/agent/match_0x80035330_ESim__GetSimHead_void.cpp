// 0x80035330 ESim::GetSimHead(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x628(3)"
extern "C" int f_80035330() {}
