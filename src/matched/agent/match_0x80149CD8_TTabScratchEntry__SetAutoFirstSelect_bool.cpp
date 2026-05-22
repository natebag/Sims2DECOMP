// 0x80149CD8 TTabScratchEntry::SetAutoFirstSelect(bool) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 0,0x110(3); cmplwi 4,0; rlwinm 0,0,0,24,22; sth 0,0x110(3); beqlr; ori 0,0,256; sth 0,0x110(3)"
extern "C" void f_80149CD8() {}
