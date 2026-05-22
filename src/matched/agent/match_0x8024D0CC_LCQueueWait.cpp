// 0x8024D0CC LCQueueWait (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="0:; mfspr 4,920; rlwinm 4,4,8,28,31; cmpw 4,3; bgt 0b"
extern "C" int f_8024D0CC() {}
