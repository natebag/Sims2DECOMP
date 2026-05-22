// 0x80149E10 TTabScratchEntry::GetAd(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,4,0,27; addi 4,4,8; add 3,3,4"
extern "C" int f_80149E10() {}
