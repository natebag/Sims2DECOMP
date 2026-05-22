// 0x80138358 Room::GetArea(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x4c(3); rlwinm 0,3,1,31,31; add 3,3,0; srawi 3,3,1"
extern "C" int f_80138358() {}
