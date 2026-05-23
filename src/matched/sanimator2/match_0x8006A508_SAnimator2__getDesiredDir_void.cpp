// 0x8006A508 SAnimator2::getDesiredDir(void) (404 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stw 31,0x24(1); stw 0,0x34(1); mr 31,3; lwz 5,0x14(31); cmpwi 5,0; bne 0f; lwz 6,0xc(31); lis 5,17200; lis 8,-32707; lwz 11,0x0(6); mr 7,10; lfd f13,0x4cf0(8); lwz 9,0x4(11); lwz 0,0xc(11); subf 0,9,0; xoris 0,0,32768; stw 0,0x1c(1); stw 5,0x18(1); lfd f0,0x18(1); fsub f0,f0,f13; frsp f0,f0; stfs f0,0x8(1); lwz 9,0x0(6); lwz 11,0x0(9); lwz 0,0x8(9); subf 0,11,0; xoris 0,0,32768; stw 0,0x1c(1); stw 5,0x18(1); b 1f; 0:; lwz 4,0xc(31); addi 8,5,-1; rlwinm 8,8,3,0,28; rlwinm 5,5,3,0,28; lwz 9,0x0(4); lis 3,17200; lis 6,-32707; add 10,9,8; lfd f13,0x4cf0(6); add 9,9,5; mr 7,11; lwz 0,0x4(9); lwz 9,0x4(10); subf 0,9,0; xoris 0,0,32768; stw 0,0x1c(1); stw 3,0x18(1); lfd f0,0x18(1); fsub f0,f0,f13; frsp f0,f0; stfs f0,0x8(1); lwz 9,0x0(4); lwzx 11,9,8; lwzx 0,9,5; subf 0,11,0; xoris 0,0,32768; stw 0,0x1c(1); stw 3,0x18(1); 1:; lfd f0,0x18(1); fsub f0,f0,f13; frsp f0,f0; stfs f0,0xc(1); lis 9,-32707; lfs f0,0x8(1); lfs f13,0x4cf8(9); fmr f2,f0; lfs f1,0xc(1); fcmpu 0,f0,f13; ble 2f; lis 9,-32707; lfs f0,0x4cfc(9); fcmpu 0,f2,f0; bge 2f; fcmpu 0,f1,f13; ble 2f; fcmpu 0,f1,f0; bge 2f; lfs f1,0x30(31); b 3f; 2:; fneg f1,f1; bl _s8006A508_0; lwz 0,0x18(31); cmpwi 0,4; bne 3f; lis 9,-32707; lis 11,-32707; lfs f0,0x4d00(9); lfs f31,0x4d04(11); fadds f1,f1,f0; fdivs f1,f1,f31; bl _s8006A508_1; fmuls f1,f1,f31; 3:; lwz 0,0x34(1); mtspr 8,0; lwz 31,0x24(1); lfd f31,0x28(1); addi 1,1,48"

extern "C" void _s8006A508_0();
extern "C" void _s8006A508_1();

struct SAnimator2 {
    void getDesiredDir();
};

void SAnimator2::getDesiredDir() {
}
