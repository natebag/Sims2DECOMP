// 0x80149B40 TreeTableAdScratch::GetRange(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 3,0x8(3)"
extern "C" int f_80149B40() {}
