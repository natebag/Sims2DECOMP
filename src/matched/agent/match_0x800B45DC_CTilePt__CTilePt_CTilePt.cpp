// 0x800B45DC CTilePt::CTilePt(CTilePt (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 9,0x0(4); mr 11,3; stb 9,0x0(11); lbz 0,0x1(4); stb 0,0x1(11); lbz 9,0x2(4); stb 9,0x2(11)"
extern "C" void f_800B45DC() {}
