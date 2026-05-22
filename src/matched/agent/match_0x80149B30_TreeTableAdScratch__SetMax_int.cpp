// 0x80149B30 TreeTableAdScratch::SetMax(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 0,0x6(3); subf 4,0,4; sth 4,0x8(3)"
extern "C" void f_80149B30() {}
