// 0x8015A6F4 ObjectDataBehaviorConstants::GetValue(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x14(3); rlwinm 4,4,1,0,30; lhax 3,4,9"
extern "C" int f_8015A6F4() {}
