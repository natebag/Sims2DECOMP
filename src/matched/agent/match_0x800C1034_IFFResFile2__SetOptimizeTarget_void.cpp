// 0x800C1034 IFFResFile2::SetOptimizeTarget(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 0,0x148(3)"
extern "C" void f_800C1034() {}
