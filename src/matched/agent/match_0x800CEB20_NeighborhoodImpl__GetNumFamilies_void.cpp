// 0x800CEB20 NeighborhoodImpl::GetNumFamilies(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x5c(3); lwz 3,0x60(3); subf 3,0,3; srawi 3,3,2"
extern "C" int f_800CEB20() {}
