// 0x802268E8 ObjectDataBehaviorTree::GetResID(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_802268F4" lines="bl _s802268E8_0"
extern "C" void _s802268E8_0();
extern "C" void f_802268F4();
extern "C" void f_802268E8() {}
