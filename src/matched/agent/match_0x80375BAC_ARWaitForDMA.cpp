// 0x80375BAC __ARWaitForDMA (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; addi 3,3,20480; 0:; lhz 0,0xa(3); rlwinm. 0,0,0,22,22; bne 0b"
extern "C" int f_80375BAC() {}
