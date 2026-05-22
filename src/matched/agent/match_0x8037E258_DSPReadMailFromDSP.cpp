// 0x8037E258 DSPReadMailFromDSP (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; addi 3,3,20480; lhz 0,0x4(3); lhz 3,0x6(3); rlwimi 3,0,16,0,15"
extern "C" int f_8037E258() {}
