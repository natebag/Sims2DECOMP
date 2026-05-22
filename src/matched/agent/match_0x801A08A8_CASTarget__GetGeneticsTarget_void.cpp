// 0x801A08A8 CASTarget::GetGeneticsTarget(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x1370(3)"
extern "C" int f_801A08A8() {}
