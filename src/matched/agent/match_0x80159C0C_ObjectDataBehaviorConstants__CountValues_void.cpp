// 0x80159C0C ObjectDataBehaviorConstants::CountValues(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 3,0x4(3); rlwinm 3,3,0,17,31"
extern "C" int f_80159C0C() {}
