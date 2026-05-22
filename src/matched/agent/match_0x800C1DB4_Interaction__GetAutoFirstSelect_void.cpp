// 0x800C1DB4 Interaction::GetAutoFirstSelect(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x3c(3); rlwinm 3,3,0,31,31"
extern "C" int f_800C1DB4() {}
