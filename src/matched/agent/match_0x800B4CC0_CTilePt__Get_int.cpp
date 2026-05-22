// 0x800B4CC0 CTilePt::Get(int (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,0x0(3); extsb 0,0; stw 0,0x0(4); lbz 9,0x1(3); extsb 9,9; stw 9,0x0(5)"
extern "C" void f_800B4CC0() {}
