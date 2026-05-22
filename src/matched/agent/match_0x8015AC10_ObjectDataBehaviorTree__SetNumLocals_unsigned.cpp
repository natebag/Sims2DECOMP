// 0x8015AC10 ObjectDataBehaviorTree::SetNumLocals(unsigned (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x54(3); stb 4,0x6(9)"
extern "C" void f_8015AC10() {}
