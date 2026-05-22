// 0x80149C44 TTabScratchEntry::SetAvailableToAdults(bool) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 0,0x110(3); cmplwi 4,0; rlwinm 0,0,0,26,24; sth 0,0x110(3); bnelr; ori 0,0,64; sth 0,0x110(3)"
extern "C" void f_80149C44() {}
