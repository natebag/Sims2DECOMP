// 0x8006622C SAnimator2::playRumble(RumbleDataElement (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); lwz 29,-21432(13); mr 30,3; mr 31,4; li 3,-1; lwz 11,0xbc(29); cmpwi 11,0; beq 0f; lwz 11,0x0(11); lwz 10,0x8(30); lwz 9,0x0(11); lwz 0,0x14(9); cmpw 0,10; bne 0f; lwz 3,-26524(13); li 4,0; bl _s8006622C_0; 0:; lwz 11,0xc0(29); cmpwi 11,0; beq 1f; lwz 11,0x0(11); lwz 10,0x8(30); lwz 9,0x0(11); lwz 0,0x14(9); cmpw 0,10; bne 1f; lwz 3,-26524(13); li 4,1; bl _s8006622C_1; 1:; cmpwi 3,-1; beq 2f; lis 9,-32697; lwz 11,0x5f14(9); lwz 0,0x4(11); cmpwi 0,0; beq 2f; lis 9,-32707; lfs f3,0x4(31); lfs f0,0x4a68(9); fcmpu 0,f3,f0; ble 2f; lhz 0,0x2(31); lis 7,17200; lis 11,-32707; stw 0,0x14(1); lis 8,-32707; lfd f0,0x4a70(11); mr 10,9; stw 7,0x10(1); rlwinm 4,3,0,24,31; lfs f13,0x4a78(8); fmr f4,f3; lfd f2,0x10(1); lhz 0,0x0(31); fsub f2,f2,f0; lwz 3,0x110(29); frsp f2,f2; stw 0,0x14(1); fdivs f2,f2,f13; stw 7,0x10(1); lfd f1,0x10(1); fsub f1,f1,f0; frsp f1,f1; bl _s8006622C_2; 2:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"

extern "C" void _s8006622C_0();
extern "C" void _s8006622C_1();
extern "C" void _s8006622C_2();

struct SAnimator2 {
    void playRumble_RumbleDataElement();
};

void SAnimator2::playRumble_RumbleDataElement() {
}
