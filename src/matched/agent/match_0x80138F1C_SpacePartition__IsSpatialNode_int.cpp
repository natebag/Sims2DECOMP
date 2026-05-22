// 0x80138F1C SpacePartition::IsSpatialNode(int) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 4,4,1; subfic 3,4,2; subfe 3,3,3; neg 3,3"
extern "C" int f_80138F1C() {}
