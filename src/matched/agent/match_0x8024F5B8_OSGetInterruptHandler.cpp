// 0x8024F5B8 __OSGetInterruptHandler (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="extsh 0,3; lwz 3,-23664(13); rlwinm 0,0,2,0,29; lwzx 3,3,0"
extern "C" int f_8024F5B8() {}
