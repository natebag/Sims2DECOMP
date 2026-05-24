// 0x8016F304 CasSimRenderer::DrawShadow(ERC (388 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-304(1); mfspr 0,8; stfd f31,0x128(1); stmw 28,0x118(1); stw 0,0x134(1); mr 28,3; mr 29,4; addi 3,1,8; mr 30,3; bl _s8016F304_0; lis 10,-32706; lis 9,-32706; lfs f0,0x1740(10); lis 11,-32706; lfs f31,0x1744(9); mr 3,30; lfs f13,0x1748(11); addi 9,1,72; stfs f0,0x2c(1); mr 4,9; stfs f0,0x28(1); stfs f31,0x30(1); stfs f31,0x48(1); stfs f13,0x8(9); stfs f31,0x4(9); bl _s8016F304_1; lwz 8,-26704(13); addi 5,1,88; addi 3,1,216; mr 4,30; lwz 11,0xa0(8); lwz 12,0xa4(8); addi 8,8,160; stw 11,0x58(1); stw 12,0x5c(1); lwz 9,0x8(8); lwz 10,0xc(8); stw 9,0x60(1); stw 10,0x64(1); lwz 11,0x10(8); lwz 12,0x14(8); stw 11,0x68(1); stw 12,0x6c(1); lwz 9,0x18(8); lwz 10,0x1c(8); stw 9,0x70(1); stw 10,0x74(1); lwz 11,0x20(8); lwz 12,0x24(8); stw 11,0x78(1); stw 12,0x7c(1); lwz 9,0x28(8); lwz 10,0x2c(8); stw 9,0x80(1); stw 10,0x84(1); lwz 11,0x30(8); lwz 12,0x34(8); stw 11,0x88(1); stw 12,0x8c(1); lwz 9,0x38(8); lwz 10,0x3c(8); stw 9,0x90(1); stw 10,0x94(1); bl _s8016F304_2; addi 4,1,216; mr 3,30; bl _s8016F304_3; addi 3,1,152; mr 4,30; bl _s8016F304_4; lwz 9,0x70(29); li 5,0; fmr f1,f31; mr 4,30; lwz 0,0xfc(9); lha 3,0xf8(9); mtspr 8,0; add 3,29,3; blrl; lwz 3,0x170(28); mr 4,29; bl _s8016F304_5; lwz 9,0x70(29); fmr f1,f31; addi 4,1,88; li 5,0; lha 3,0xf8(9); lwz 0,0xfc(9); add 3,29,3; mtspr 8,0; blrl; lwz 0,0x134(1); mtspr 8,0; lmw 28,0x118(1); lfd f31,0x128(1); addi 1,1,304"

extern "C" void _s8016F304_0();
extern "C" void _s8016F304_1();
extern "C" void _s8016F304_2();
extern "C" void _s8016F304_3();
extern "C" void _s8016F304_4();
extern "C" void _s8016F304_5();

struct CasSimRenderer {
    void DrawShadow();
};

void CasSimRenderer::DrawShadow() {
}
