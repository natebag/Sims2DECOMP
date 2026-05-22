// 0x8015AB94 ObjectDataBehaviorTree::SetNumParams(unsigned (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x54(3); stb 4,0x5(9)"
extern "C" void f_8015AB94() {}
