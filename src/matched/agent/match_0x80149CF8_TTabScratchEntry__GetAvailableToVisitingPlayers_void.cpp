// 0x80149CF8 TTabScratchEntry::GetAvailableToVisitingPlayers(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 3,0x110(3); rlwinm 3,3,23,31,31"
extern "C" int f_80149CF8() {}
