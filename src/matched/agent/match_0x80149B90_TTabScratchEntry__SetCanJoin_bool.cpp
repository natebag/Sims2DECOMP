// 0x80149B90 TTabScratchEntry::SetCanJoin(bool) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 0,0x110(3); cmplwi 4,0; rlwinm 0,0,0,31,29; sth 0,0x110(3); beqlr; ori 0,0,2; sth 0,0x110(3)"
extern "C" void f_80149B90() {}
