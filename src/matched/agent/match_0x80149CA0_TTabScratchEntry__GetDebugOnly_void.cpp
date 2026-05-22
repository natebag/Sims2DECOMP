// 0x80149CA0 TTabScratchEntry::GetDebugOnly(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 3,0x110(3); rlwinm 3,3,25,31,31"
extern "C" int f_80149CA0() {}
