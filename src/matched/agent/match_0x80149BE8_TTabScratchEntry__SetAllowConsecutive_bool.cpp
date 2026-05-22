// 0x80149BE8 TTabScratchEntry::SetAllowConsecutive(bool) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 0,0x110(3); cmplwi 4,0; rlwinm 0,0,0,29,27; sth 0,0x110(3); beqlr; ori 0,0,8; sth 0,0x110(3)"
extern "C" void f_80149BE8() {}
