// 0x8024D0C0 LCQueueLength (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 4,920; rlwinm 3,4,8,28,31"
extern "C" int f_8024D0C0() {}
