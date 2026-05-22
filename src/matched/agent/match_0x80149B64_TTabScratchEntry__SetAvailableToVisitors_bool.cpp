// 0x80149B64 TTabScratchEntry::SetAvailableToVisitors(bool) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 0,0x110(3); cmplwi 4,0; clrlwi 0,0,30; sth 0,0x110(3); beqlr; ori 0,0,1; sth 0,0x110(3)"
extern "C" void f_80149B64() {}
