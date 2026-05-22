// 0x802FFF10 EWindow::ScaleOutputRectForScreenshot(TRect<float> (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 11,-32693; lis 9,-32702; lfs f13,0x8f4(11); lfs f0,0x8(3); addi 11,11,2292; lfs f11,-2208(9); lfs f7,0x0(3); lis 9,-32693; fsubs f13,f13,f11; lfs f12,0xc(3); fsubs f9,f0,f7; lfs f8,0x4(3); fmadds f13,f9,f13,f0; addi 10,9,2304; stfs f13,0x8(3); fsubs f10,f12,f8; lfs f0,0x4(11); fsubs f0,f0,f11; fmadds f0,f10,f0,f12; stfs f0,0xc(3); lfs f12,0x900(9); lfs f11,0x4(10); fmuls f9,f9,f12; fmuls f10,f10,f11; fsubs f13,f13,f9; fsubs f0,f0,f10; stfs f13,0x8(3); fsubs f7,f7,f9; stfs f0,0xc(3); fsubs f8,f8,f10; stfs f7,0x0(3); stfs f8,0x4(3)"
extern "C" void f_802FFF10() {}
