// 0x800B49EC CTilePt::GetRow(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,0x1(3); lbz 3,0x0(3); extsb 0,0; extsb 3,3; add 3,3,0"
extern "C" int f_800B49EC() {}
