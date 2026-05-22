// 0x80149C34 TTabScratchEntry::GetAvailableToAdults(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 3,0x110(3); xori 3,3,64; rlwinm 3,3,26,31,31"
extern "C" int f_80149C34() {}
