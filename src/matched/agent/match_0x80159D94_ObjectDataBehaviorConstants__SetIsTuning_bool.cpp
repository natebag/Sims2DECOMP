// 0x80159D94 ObjectDataBehaviorConstants::SetIsTuning(bool) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 0,0x4(3); cmplwi 4,0; rlwinm 0,0,0,17,31; sth 0,0x4(3); beqlr; ori 0,0,32768; sth 0,0x4(3)"
extern "C" void f_80159D94() {}
