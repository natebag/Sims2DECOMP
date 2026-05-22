// 0x8015AC48 ObjectDataBehaviorTree::GetResID(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 3,0x4(3)"
extern "C" int f_8015AC48() {}
