// 0x802C5CE4 EBoundTreeNode::Destruct(EBoundTreeNode (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; addi 9,9,-28472; stw 9,0x0(3)"
extern "C" void f_802C5CE4() {}
