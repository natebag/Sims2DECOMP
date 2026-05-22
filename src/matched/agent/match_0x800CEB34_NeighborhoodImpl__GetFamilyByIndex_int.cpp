// 0x800CEB34 NeighborhoodImpl::GetFamilyByIndex(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x5c(3); rlwinm 4,4,2,0,29; lwzx 3,9,4"
extern "C" int f_800CEB34() {}
