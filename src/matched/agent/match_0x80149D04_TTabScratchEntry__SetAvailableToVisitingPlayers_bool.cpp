// 0x80149D04 TTabScratchEntry::SetAvailableToVisitingPlayers(bool) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 0,0x110(3); cmplwi 4,0; rlwinm 0,0,0,23,21; sth 0,0x110(3); beqlr; ori 0,0,512; sth 0,0x110(3)"
extern "C" void f_80149D04() {}
