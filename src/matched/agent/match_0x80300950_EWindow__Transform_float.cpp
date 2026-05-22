// 0x80300950 EWindow::Transform(float, (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f13,0x0(3); lfs f0,0x30(3); fmadds f1,f1,f13,f0; stfs f1,0x0(4); lfs f13,0x34(3); lfs f0,0x14(3); fmadds f2,f2,f0,f13; stfs f2,0x0(5)"
extern "C" void f_80300950() {}
