// 0x8024BAEC __OSGetExceptionHandler (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,3,0,24,31; lwz 3,-23708(13); rlwinm 0,0,2,0,29; lwzx 3,3,0"
extern "C" int f_8024BAEC() {}
