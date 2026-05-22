// 0x80159D88 ObjectDataBehaviorConstants::IsTuning(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 3,0x4(3); rlwinm 3,3,17,31,31"
extern "C" int f_80159D88() {}
