// 0x801A08E8 CASGeneticsTarget::GetWarnOnGenerate(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x300(3); rlwinm 3,3,27,31,31"
extern "C" int f_801A08E8() {}
