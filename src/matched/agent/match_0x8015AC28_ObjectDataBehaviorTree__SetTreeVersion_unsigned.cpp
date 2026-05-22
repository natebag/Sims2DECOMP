// 0x8015AC28 ObjectDataBehaviorTree::SetTreeVersion(unsigned (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x54(3); stw 4,0x8(9)"
extern "C" void f_8015AC28() {}
