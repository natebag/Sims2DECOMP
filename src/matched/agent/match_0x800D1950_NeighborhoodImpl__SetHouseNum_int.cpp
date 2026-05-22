// 0x800D1950 NeighborhoodImpl::SetHouseNum(int) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x70(3)"
extern "C" void f_800D1950() {}
