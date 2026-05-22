// 0x801A07F8 CASTarget::IsShuttingdown(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x1630(3)"
extern "C" int f_801A07F8() {}
