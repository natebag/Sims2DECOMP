// 0x802C5D40 EBoundTreeNode::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-13028(9)"
extern "C" int f_802C5D40() {}
