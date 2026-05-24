// 0x802FFF94 EWindow::ScaleScissorRectForScreenshot(TRect<float> (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 11,-32693; lfs f7,0x0(3); lfs f0,0x8f4(11); addi 10,11,2292; lfs f8,0x4(3); lis 8,-32693; fmuls f7,f7,f0; lfs f10,0x8(3); stfs f7,0x0(3); lis 9,-32702; lfs f11,0xc(3); addi 7,8,2304; lfs f0,0x4(10); lfs f5,-2204(9); fmuls f8,f8,f0; stfs f8,0x4(3); lfs f0,0x8f4(11); fmuls f10,f10,f0; stfs f10,0x8(3); lfs f0,0x4(10); fmuls f11,f11,f0; stfs f11,0xc(3); lfs f12,0x0(4); lfs f0,0x8(4); lfs f6,0x4(4); lfs f13,0xc(4); fsubs f0,f0,f12; lfs f9,0x900(8); fadds f0,f0,f5; lfs f12,0x4(7); fsubs f13,f13,f6; fadds f13,f13,f5; fmuls f0,f0,f9; fmuls f13,f13,f12; fsubs f10,f10,f0; fsubs f11,f11,f13; stfs f10,0x8(3); fsubs f7,f7,f0; stfs f11,0xc(3); fsubs f8,f8,f13; stfs f7,0x0(3); stfs f8,0x4(3)"

struct EWindow {
    void ScaleScissorRectForScreenshot_TRect();
};

void EWindow::ScaleScissorRectForScreenshot_TRect() {
}
