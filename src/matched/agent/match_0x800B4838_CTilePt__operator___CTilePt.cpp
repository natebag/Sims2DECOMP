// 0x800B4838 CTilePt::operator-=(CTilePt (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 10,3; lbz 9,0x0(4); lbz 0,0x0(10); lbz 11,0x1(10); subf 0,9,0; stb 0,0x0(10); lbz 9,0x1(4); subf 11,9,11; stb 11,0x1(10)"
extern "C" void f_800B4838() {}
