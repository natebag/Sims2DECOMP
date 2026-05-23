// 0x80068AB4 SAnimator2::setAwarenessFollowStart(float) (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stw 31,0xc(1); stw 0,0x1c(1); mr 31,3; fmr f31,f1; lwz 9,0x61c(31); lis 11,-32707; lwz 3,0x8(31); lis 10,-32707; rlwinm 9,9,0,31,24; li 0,6; lfs f1,0x4bd4(11); addi 3,3,820; lfs f2,0x4bd8(10); li 4,1; stw 0,0x18(31); stw 9,0x61c(31); bl _s80068AB4_0; lfs f0,0x30(31); lis 9,-32707; lfs f13,0x4bdc(9); li 0,0; fadds f31,f31,f0; stw 0,0x668(31); stfs f31,0xb4(31); fcmpu 0,f31,f13; bge 1f; lis 9,-32707; lfs f0,0x4be0(9); 0:; fadds f31,f31,f0; fcmpu 0,f31,f13; blt 0b; stfs f31,0xb4(31); 1:; lis 9,-32707; lfs f13,0xb4(31); lfs f0,0x4be4(9); fcmpu 0,f13,f0; ble 3f; lis 9,-32707; fmr f11,f0; lfs f12,0x4be0(9); 2:; fsubs f0,f13,f12; fmr f13,f0; fcmpu 0,f0,f11; bgt 2b; stfs f0,0xb4(31); 3:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0xc(1); lfd f31,0x10(1); addi 1,1,24"

extern "C" void _s80068AB4_0();

struct SAnimator2 {
    void setAwarenessFollowStart();
};

void SAnimator2::setAwarenessFollowStart() {
}
