// 0x8024F550 OSDisableInterrupts (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfmsr 3; rlwinm 4,3,0,17,15; mtmsr 4; rlwinm 3,3,17,31,31"
extern "C" int f_8024F550() {}
