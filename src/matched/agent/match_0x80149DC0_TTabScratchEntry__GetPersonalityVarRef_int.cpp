// 0x80149DC0 TTabScratchEntry::GetPersonalityVarRef(int) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,4,0,27; addi 4,4,8; add 3,3,4; addi 3,3,4"
extern "C" int f_80149DC0() {}
