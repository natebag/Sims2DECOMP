// 0x80159C44 ObjectDataBehaviorConstants::SetValue(int, (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x14(3); rlwinm 4,4,1,0,30; sthx 5,4,9"
extern "C" void f_80159C44() {}
