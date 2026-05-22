// 0x802C5D58 EBoundTreeNode::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-13020(9)"
extern "C" int f_802C5D58() {}
