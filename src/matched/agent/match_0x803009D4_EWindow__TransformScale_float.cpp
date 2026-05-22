// 0x803009D4 EWindow::TransformScale(float, (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,0x0(3); fmuls f1,f1,f0; stfs f1,0x0(4); lfs f0,0x14(3); fmuls f2,f2,f0; stfs f2,0x0(5)"
extern "C" void f_803009D4() {}
