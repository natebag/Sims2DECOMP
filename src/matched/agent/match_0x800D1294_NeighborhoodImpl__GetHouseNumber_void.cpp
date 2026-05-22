// 0x800D1294 NeighborhoodImpl::GetHouseNumber(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x70(3)"
extern "C" int f_800D1294() {}
