// 0x801BDA50 ITBTarget::GetUserReadTime(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0x9c(3)"
extern "C" int f_801BDA50() {}
