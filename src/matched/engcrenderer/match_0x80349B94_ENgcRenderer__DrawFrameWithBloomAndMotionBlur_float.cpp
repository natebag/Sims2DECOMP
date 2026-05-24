// 0x80349B94 ENgcRenderer::DrawFrameWithBloomAndMotionBlur(float, (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f30,0x8(1); stfd f31,0x10(1); stw 0,0x1c(1); fmr f31,f1; fmr f30,f2; bl _s80349B94_0; li 3,152; li 4,2; li 5,4; bl _s80349B94_1; lis 11,-32702; lis 9,-13311; lfs f13,0x1f1c(11); fneg f12,f31; fneg f7,f30; lis 11,-32702; stfs f13,-32768(9); stfs f13,-32768(9); stfs f13,-32768(9); stfs f13,-32768(9); stfs f13,-32768(9); stfs f31,-32768(9); stfs f30,-32768(9); stfs f12,-32768(9); stfs f30,-32768(9); stfs f31,-32768(9); stfs f7,-32768(9); stfs f12,-32768(9); stfs f7,-32768(9); stfs f13,-32768(9); lfs f0,0x1f20(11); stfs f13,-32768(9); stfs f13,-32768(9); fadds f9,f30,f0; stfs f0,-32768(9); fsubs f8,f0,f30; stfs f13,-32768(9); fadds f11,f31,f0; stfs f13,-32768(9); fsubs f10,f0,f31; stfs f0,-32768(9); stfs f31,-32768(9); stfs f9,-32768(9); stfs f12,-32768(9); stfs f9,-32768(9); stfs f31,-32768(9); stfs f8,-32768(9); stfs f12,-32768(9); stfs f8,-32768(9); stfs f13,-32768(9); stfs f0,-32768(9); stfs f0,-32768(9); stfs f13,-32768(9); stfs f13,-32768(9); stfs f0,-32768(9); stfs f13,-32768(9); stfs f11,-32768(9); stfs f30,-32768(9); stfs f10,-32768(9); stfs f30,-32768(9); stfs f11,-32768(9); stfs f7,-32768(9); stfs f10,-32768(9); stfs f7,-32768(9); stfs f0,-32768(9); stfs f13,-32768(9); stfs f0,-32768(9); stfs f0,-32768(9); stfs f13,-32768(9); stfs f0,-32768(9); stfs f0,-32768(9); stfs f11,-32768(9); stfs f9,-32768(9); stfs f10,-32768(9); stfs f9,-32768(9); stfs f11,-32768(9); stfs f8,-32768(9); stfs f10,-32768(9); stfs f8,-32768(9); stfs f0,-32768(9); stfs f0,-32768(9); lwz 0,0x1c(1); mtspr 8,0; lfd f30,0x8(1); lfd f31,0x10(1); addi 1,1,24"

extern "C" void _s80349B94_0();
extern "C" void _s80349B94_1();

struct ENgcRenderer {
    void DrawFrameWithBloomAndMotionBlur();
};

void ENgcRenderer::DrawFrameWithBloomAndMotionBlur() {
}
