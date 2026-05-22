// 0x800D1928 NeighborhoodImpl::GetNumNeighborHouses(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4c(3); lwz 3,0x50(3); subf 3,0,3; srawi 3,3,2"
extern "C" int f_800D1928() {}
