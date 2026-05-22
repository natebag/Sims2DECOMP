// 0x800D18A8 NeighborhoodImpl::GetHighestLevelCompleted(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 3,0x84(3)"
extern "C" int f_800D18A8() {}
