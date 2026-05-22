// 0x800B4A04 CTilePt::GetColumn(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,0x1(3); lbz 3,0x0(3); extsb 0,0; extsb 3,3; subf 3,0,3"
extern "C" int f_800B4A04() {}
