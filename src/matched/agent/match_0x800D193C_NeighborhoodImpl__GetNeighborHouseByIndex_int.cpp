// 0x800D193C NeighborhoodImpl::GetNeighborHouseByIndex(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4c(3); rlwinm 4,4,2,0,29; lwzx 3,9,4"
extern "C" int f_800D193C() {}
