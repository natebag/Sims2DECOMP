// 0x8037E244 DSPReadCPUToDSPMbox (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; lhzu 0,0x5000(3); lhz 3,0x2(3); rlwimi 3,0,16,0,15"
extern "C" int f_8037E244() {}
