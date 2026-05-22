// 0x80149D24 TTabScratchEntry::GetIgnorePrefixTree(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 3,0x110(3); rlwinm 3,3,22,31,31"
extern "C" int f_80149D24() {}
