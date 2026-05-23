// 0x8005F958 SAnimator2::endFollowDone(void) (504 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 28,0x18(1); stw 0,0x34(1); mr 31,3; lwz 9,0xc(31); lbz 11,0x5f8(31); lwz 10,0x0(9); lwz 0,0x4(9); cmpwi 11,0; subf 0,10,0; srawi 28,0,3; bne 2f; lwz 3,0x8(31); li 4,1; addi 3,3,820; bl _s8005F958_0; cmpwi 3,0; bne 2f; li 0,0; mr 3,31; stw 0,0x11c(31); bl _s8005F958_1; lbz 0,0x5fa(31); mr 30,3; cmpwi 0,0; beq 0f; mr 3,31; bl _s8005F958_2; 0:; lwz 0,0x61c(31); andis. 29,0,16; bne 1f; lwz 3,0x4(31); addi 5,1,8; mr 4,30; bl _s8005F958_3; lwz 9,0x8(1); lis 11,-32707; lwz 3,0x8(31); li 4,1; lwz 5,0x0(9); li 6,-1; lfs f1,0x4728(11); addi 3,3,820; li 7,0; bl _s8005F958_4; stw 29,0xc8(31); lis 9,-32707; lwz 0,0x61c(31); mr. 30,3; lfs f0,0x472c(9); lwz 11,0x8(1); oris 0,0,1; stfs f0,0xd0(31); stw 11,0xd4(31); stw 0,0x61c(31); beq 1f; lwz 3,0x8(31); mr 4,30; lfs f1,0xfc(31); addi 3,3,820; bl _s8005F958_5; stb 29,0xd(30); 1:; mr 3,31; bl _s8005F958_6; 2:; lwz 9,0x61c(31); li 0,2; stw 0,0x10(31); cmpwi 28,1; rlwinm 9,9,0,27,24; stw 9,0x61c(31); ble 3f; lwz 5,0xc(31); addi 8,28,-2; rlwinm 8,8,3,0,28; lwz 9,0x0(5); lis 6,17200; lis 10,-32707; mr 7,11; add 9,9,8; lfd f13,0x4730(10); lwz 0,0x4(9); xoris 0,0,32768; stw 0,0x14(1); stw 6,0x10(1); lfd f0,0x10(1); fsub f0,f0,f13; frsp f0,f0; stfs f0,0x1c(31); lwz 9,0x0(5); lwzx 0,9,8; xoris 0,0,32768; stw 0,0x14(1); stw 6,0x10(1); lfd f0,0x10(1); fsub f0,f0,f13; b 4f; 3:; mr 3,31; lis 30,17200; bl _s8005F958_7; xoris 3,3,32768; stw 3,0x14(1); lis 9,-32707; lfd f31,0x4730(9); mr 3,31; stw 30,0x10(1); lfd f0,0x10(1); fsub f0,f0,f31; frsp f0,f0; stfs f0,0x1c(31); bl _s8005F958_8; xoris 3,3,32768; stw 3,0x14(1); stw 30,0x10(1); lfd f0,0x10(1); fsub f0,f0,f31; 4:; frsp f0,f0; stfs f0,0x20(31); li 3,0; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x18(1); lfd f31,0x28(1); addi 1,1,48"

extern "C" void _s8005F958_0();
extern "C" void _s8005F958_1();
extern "C" void _s8005F958_2();
extern "C" void _s8005F958_3();
extern "C" void _s8005F958_4();
extern "C" void _s8005F958_5();
extern "C" void _s8005F958_6();
extern "C" void _s8005F958_7();
extern "C" void _s8005F958_8();

struct SAnimator2 {
    void endFollowDone();
};

void SAnimator2::endFollowDone() {
}
