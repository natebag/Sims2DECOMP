// 0x80149D7C TTabScratchEntry::GetManualOnly(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 0,0x114(3); cmplwi 7,0,99; mfcr 3; rlwinm 3,3,30,31,31"
extern "C" int f_80149D7C() {}
