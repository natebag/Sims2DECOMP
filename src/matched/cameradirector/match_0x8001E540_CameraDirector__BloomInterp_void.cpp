// 0x8001E540 CameraDirector::BloomInterp(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32707; lis 11,-32707; lfs f13,-6684(9); lfs f0,0x2d4(3); lfs f12,-6680(11); fmuls f10,f0,f13; fcmpu 0,f10,f12; cror 3,2,1; bns 0f; lwz 0,0x31c(3); fmr f10,f12; rlwinm 0,0,0,0,30; stw 0,0x31c(3); 0:; lwz 11,-26392(13); fsubs f0,f12,f10; lfs f13,0x2f8(3); lfs f1,0x2ec(3); lfs f2,0x2f0(3); fmuls f13,f10,f13; lfs f3,0x2f4(3); fmuls f1,f10,f1; lwz 9,0x0(11); fmuls f2,f10,f2; fmuls f3,f10,f3; lfs f12,0x2dc(3); lfs f11,0x2e0(3); lfs f10,0x2e4(3); fmadds f1,f0,f12,f1; lfs f4,0x2e8(3); fmadds f2,f0,f11,f2; lha 3,0x1a8(9); fmadds f3,f0,f10,f3; lwz 0,0x1ac(9); fmadds f4,f0,f4,f13; add 3,11,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

struct CameraDirector {
    void BloomInterp();
};

void CameraDirector::BloomInterp() {
}
