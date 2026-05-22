// 0x80069114 SAnimator2::GetPlayerControl(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x61c(3); li 3,0; andi. 9,0,1; beqlr; li 3,1"
extern "C" int f_80069114() {}
