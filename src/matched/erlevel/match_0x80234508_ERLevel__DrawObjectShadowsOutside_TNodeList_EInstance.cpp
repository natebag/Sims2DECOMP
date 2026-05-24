// 0x80234508 ERLevel::DrawObjectShadowsOutside(TNodeList<EInstance (568 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-144(1); mfspr 0,8; stfd f29,0x78(1); stfd f30,0x80(1); stfd f31,0x88(1); stmw 25,0x5c(1); stw 0,0x94(1); mr 30,3; lis 9,-32704; addi 11,30,24668; lfs f11,-2848(9); lfs f0,0x8(11); lis 9,-32704; lfs f12,0x605c(30); mr 25,4; lfs f13,0x4(11); fsubs f0,f0,f11; lfs f10,-2844(9); addi 3,1,8; stfs f0,0x10(1); fcmpu 0,f12,f10; stfs f13,0xc(1); stfs f12,0x8(1); bne 0f; lfs f0,0x4(3); fcmpu 0,f0,f10; bne 0f; lfs f0,0x8(3); fcmpu 0,f0,f10; beq 1f; 0:; mr 4,3; bl _s80234508_0; 1:; lis 11,-32704; lfs f13,0x10(1); lfs f0,-2840(11); lis 9,-32704; lfs f31,-2844(9); li 29,2; fdivs f0,f0,f13; lfs f12,0x8(1); stfs f31,0x38(1); li 31,5; stfs f31,0x34(1); mr 10,29; stfs f31,0x30(1); mr 26,29; lwz 11,0x34(1); mr 27,31; lwz 0,0x30(1); lwz 9,0x38(1); lfs f13,0xc(1); stw 0,0x18(1); stw 11,0x1c(1); stw 9,0x20(1); stw 0,0x24(1); stw 11,0x28(1); stw 9,0x2c(1); fmuls f29,f12,f0; stfs f0,0x10(1); fmuls f30,f13,f0; fcmpu 0,f29,f31; bge 2f; mr 26,31; mr 27,29; 2:; fcmpu 0,f30,f31; bge 3f; mr 29,31; mr 31,10; 3:; addis 9,30,3; addi 11,9,-24160; mr 28,9; lwz 0,0xb0(11); addi 9,9,-24096; cmpw 0,9; beq 4f; stw 9,0xb0(11); mr 4,9; lwz 3,0x98(11); li 5,0; fmr f1,f31; lwz 9,0x70(3); lha 0,0xf8(9); lwz 9,0xfc(9); add 3,3,0; mtspr 8,9; blrl; 4:; lwz 30,0x0(25); cmpwi 30,0; beq 7f; rlwinm 25,26,2,0,29; rlwinm 27,27,2,0,29; rlwinm 26,29,2,0,29; rlwinm 29,31,2,0,29; 5:; lwz 31,0x0(30); addi 4,1,64; stfs f31,0x38(1); stfs f31,0x34(1); addi 9,31,60; stfs f31,0x30(1); lwz 10,0x34(1); lwz 0,0x30(1); lwz 11,0x38(1); stw 0,0x40(1); stw 10,0x44(1); stw 0,0x4c(1); stw 10,0x50(1); stw 11,0x48(1); stw 11,0x54(1); lfs f13,0x3c(31); lfsx f0,25,9; lwz 3,-24004(28); fmadds f0,f29,f0,f13; stfs f0,0x40(1); lfs f0,0x4(9); lfsx f13,26,9; fmadds f13,f30,f13,f0; stfs f13,0x44(1); lfs f13,0xc(9); lfsx f0,27,9; fmadds f0,f29,f0,f13; stfs f0,0x4c(1); lfs f13,0x10(9); lfsx f0,29,9; fmadds f0,f30,f0,f13; stfs f0,0x50(1); bl _s80234508_1; cmpwi 3,0; bne 6f; mr 3,31; addi 4,28,-24160; bl _s80234508_2; 6:; lwz 30,0x8(30); cmpwi 30,0; bne 5b; 7:; lwz 0,0x94(1); mtspr 8,0; lmw 25,0x5c(1); lfd f29,0x78(1); lfd f30,0x80(1); lfd f31,0x88(1); addi 1,1,144"

extern "C" void _s80234508_0();
extern "C" void _s80234508_1();
extern "C" void _s80234508_2();

struct ERLevel {
    void DrawObjectShadowsOutside_TNodeList_EInstance();
};

void ERLevel::DrawObjectShadowsOutside_TNodeList_EInstance() {
}
