// 0x80060A84 SAnimator2::sidestepAlongNode(float (412 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f31,0x30(1); stmw 30,0x28(1); stw 0,0x3c(1); mr 31,3; mr 30,4; lwz 4,0x108(31); bl _s80060A84_0; lwz 7,0xc(31); lwz 8,0x14(31); lis 6,17200; lwz 9,0x0(7); fmr f31,f1; rlwinm 8,8,3,0,28; lis 11,-32707; add 9,9,8; lfd f13,0x47a8(11); lwz 0,0x4(9); mr 11,10; lfs f0,0x1c(31); xoris 0,0,32768; lfs f12,0x20(31); stw 0,0x24(1); stw 6,0x20(1); lfd f1,0x20(1); fsub f1,f1,f13; frsp f1,f1; stfs f1,0x8(1); fsubs f1,f1,f0; lwz 9,0x0(7); lwzx 0,9,8; stfs f1,0x10(1); xoris 0,0,32768; stw 0,0x24(1); stw 6,0x20(1); lfd f0,0x20(1); fsub f0,f0,f13; frsp f0,f0; fsubs f12,f0,f12; stfs f0,0xc(1); fmuls f13,f12,f12; stfs f12,0x14(1); fmadds f1,f1,f1,f13; bl _s80060A84_1; lis 9,-32707; fmr f11,f1; lfs f0,0x47b0(9); fcmpu 0,f11,f0; bge 0f; lfs f0,0x8(1); lfs f13,0xc(1); stfs f0,0x1c(31); stfs f13,0x20(31); b 2f; 0:; lis 9,-32707; lfs f10,0x0(30); lfs f0,0x47b4(9); lfs f12,0x10(1); fmuls f1,f31,f10; fdivs f0,f0,f11; lfs f13,0x14(1); fmuls f12,f12,f0; fmuls f13,f13,f0; stfs f12,0x10(1); stfs f13,0x14(1); fcmpu 0,f1,f11; ble 1f; lis 9,-32707; lfs f0,0x47b8(9); fcmpu 0,f1,f0; ble 1f; fsubs f0,f1,f11; lfs f12,0x8(1); fdivs f0,f0,f1; lfs f13,0xc(1); fmuls f0,f10,f0; stfs f0,0x0(30); stfs f13,0x20(31); stfs f12,0x1c(31); b 2f; 1:; lis 9,-32707; lfs f0,0x10(1); lfs f13,0x47b8(9); addi 11,31,28; lfs f12,0x14(1); fmuls f0,f0,f1; stfs f13,0x0(30); stfs f0,0x18(1); fmuls f12,f12,f1; lfs f13,0x1c(31); stfs f12,0x1c(1); fadds f13,f13,f0; stfs f13,0x1c(31); lfs f0,0x4(11); fadds f0,f0,f12; stfs f0,0x4(11); 2:; lwz 0,0x3c(1); mtspr 8,0; lmw 30,0x28(1); lfd f31,0x30(1); addi 1,1,56"

extern "C" void _s80060A84_0();
extern "C" void _s80060A84_1();

struct SAnimator2 {
    void sidestepAlongNode();
};

void SAnimator2::sidestepAlongNode() {
}
