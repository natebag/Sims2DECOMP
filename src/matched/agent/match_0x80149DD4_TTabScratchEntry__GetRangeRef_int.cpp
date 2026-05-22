// 0x80149DD4 TTabScratchEntry::GetRangeRef(int) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,4,0,27; addi 4,4,8; add 3,3,4; addi 3,3,8"
extern "C" int f_80149DD4() {}
