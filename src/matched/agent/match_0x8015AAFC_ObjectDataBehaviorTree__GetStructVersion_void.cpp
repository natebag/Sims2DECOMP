// 0x8015AAFC ObjectDataBehaviorTree::GetStructVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x54(3); lha 3,0x0(9)"
extern "C" int f_8015AAFC() {}
