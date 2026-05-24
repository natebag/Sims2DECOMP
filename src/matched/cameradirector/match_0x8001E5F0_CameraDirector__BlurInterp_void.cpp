// 0x8001E5F0 CameraDirector::BlurInterp(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32707; lis 11,-32707; lfs f13,-6676(9); lfs f0,0x2d8(3); lfs f12,-6672(11); fmuls f10,f0,f13; fcmpu 0,f10,f12; cror 3,2,1; bns 0f; lwz 0,0x31c(3); fmr f10,f12; rlwinm 0,0,0,31,29; stw 0,0x31c(3); 0:; lfs f13,0x318(3); fsubs f0,f12,f10; lfs f1,0x30c(3); lfs f2,0x310(3); fmuls f13,f10,f13; lfs f3,0x314(3); fmuls f1,f10,f1; fmuls f2,f10,f2; lfs f12,0x2fc(3); fmuls f3,f10,f3; lfs f11,0x300(3); lfs f10,0x304(3); fmadds f1,f0,f12,f1; lfs f4,0x308(3); fmadds f2,f0,f11,f2; lwz 3,-26392(13); fmadds f3,f0,f10,f3; fmadds f4,f0,f4,f13; bl _s8001E5F0_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s8001E5F0_0();

struct CameraDirector {
    void BlurInterp();
};

void CameraDirector::BlurInterp() {
}
