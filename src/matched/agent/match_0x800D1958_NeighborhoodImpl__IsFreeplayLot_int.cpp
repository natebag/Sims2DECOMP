// 0x800D1958 NeighborhoodImpl::IsFreeplayLot(int) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 3,3,-13; subfic 3,3,3; li 3,0; adde 3,3,3"
extern "C" int f_800D1958() {}
