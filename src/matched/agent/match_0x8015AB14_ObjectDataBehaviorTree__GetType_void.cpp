// 0x8015AB14 ObjectDataBehaviorTree::GetType(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x54(3); lbz 3,0x4(9)"
extern "C" int f_8015AB14() {}
