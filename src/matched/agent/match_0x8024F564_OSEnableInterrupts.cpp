// 0x8024F564 OSEnableInterrupts (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfmsr 3; ori 4,3,32768; mtmsr 4; rlwinm 3,3,17,31,31"
extern "C" int f_8024F564() {}
