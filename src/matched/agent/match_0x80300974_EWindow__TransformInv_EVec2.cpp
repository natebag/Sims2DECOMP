// 0x80300974 EWindow::TransformInv(EVec2 (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,0x30(3); lfs f13,0x0(4); lfs f12,0x0(3); fsubs f13,f13,f0; fdivs f13,f13,f12; stfs f13,0x0(5); lfs f0,0x4(4); lfs f13,0x34(3); lfs f12,0x14(3); fsubs f0,f0,f13; fdivs f0,f0,f12; stfs f0,0x4(5)"
extern "C" void f_80300974() {}
