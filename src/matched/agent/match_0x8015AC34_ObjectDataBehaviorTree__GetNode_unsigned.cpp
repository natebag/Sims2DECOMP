// 0x8015AC34 ObjectDataBehaviorTree::GetNode(unsigned (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 4,4,12; lwz 3,0x54(3); addi 4,4,12; add 3,3,4"
extern "C" int f_8015AC34() {}
