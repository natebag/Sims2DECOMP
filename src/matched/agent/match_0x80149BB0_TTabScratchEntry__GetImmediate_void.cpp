// 0x80149BB0 TTabScratchEntry::GetImmediate(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 3,0x110(3); rlwinm 3,3,30,31,31"
extern "C" int f_80149BB0() {}
