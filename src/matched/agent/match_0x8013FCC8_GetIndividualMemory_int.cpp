// 0x8013FCC8 GetIndividualMemory(int, (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,4,1,0,30; add 0,0,4; sraw 3,3,0; rlwinm 3,3,0,29,31"
extern "C" int f_8013FCC8() {}
