// 0x80149B20 TreeTableAdScratch::GetMax(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 0,0x8(3); lha 3,0x6(3); add 3,3,0"
extern "C" int f_80149B20() {}
