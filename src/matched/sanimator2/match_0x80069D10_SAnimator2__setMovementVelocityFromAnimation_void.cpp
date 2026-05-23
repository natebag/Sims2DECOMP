// 0x80069D10 SAnimator2::setMovementVelocityFromAnimation(void) (684 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-280(1); mfspr 0,8; stfd f30,0x108(1); stfd f31,0x110(1); stmw 24,0xe8(1); stw 0,0x11c(1); mr 31,3; addi 3,1,24; mr 24,3; bl _s80069D10_0; lwz 0,0x108(31); cmpwi 0,2; bne 0f; addi 29,31,168; li 27,4; b 4f; 0:; cmpwi 0,3; bne 1f; addi 29,31,172; li 27,8; b 4f; 1:; cmpwi 0,1; beq 2f; cmpwi 0,8; bne 3f; 2:; addi 29,31,160; li 27,2; b 4f; 3:; addi 29,31,156; li 27,1; 4:; lwz 0,0x3c(31); and. 25,0,27; bne 12f; addi 4,1,216; mr 3,31; bl _s80069D10_1; lis 30,-32693; lwz 9,0xd8(1); addi 3,30,11064; lwz 4,0x0(9); bl _s80069D10_2; cmpwi 3,0; beq 12f; lwz 9,0xd8(1); addi 26,30,11064; mr 3,26; li 5,0; lwz 4,0x0(9); li 6,0; bl _s80069D10_3; mr. 30,3; beq 12f; lwz 11,0x18(30); lis 28,17200; mr 8,10; addi 0,11,-1; lis 9,-32707; xoris 0,0,32768; addi 11,11,-2; stw 0,0xe4(1); xoris 11,11,32768; lfd f31,0x4c90(9); lis 7,-32707; stw 28,0xe0(1); lfs f11,0x64(30); lfd f13,0xe0(1); stw 11,0xe4(1); fsub f13,f13,f31; lfs f10,0x4c88(7); stw 28,0xe0(1); frsp f12,f13; fmr f13,f12; lfd f0,0xe0(1); fdivs f30,f13,f11; fsub f0,f0,f31; frsp f0,f0; fdivs f0,f0,f12; fmuls f30,f30,f0; fcmpu 0,f30,f10; beq 10f; lwz 3,0x94(1); cmpwi 3,0; beq 5f; bl _s80069D10_4; stw 25,0x94(1); 5:; lwz 3,0x8(31); mr 4,24; stw 30,0x94(1); addi 3,3,820; bl _s80069D10_5; lwz 9,0x34(30); lwz 10,0xb0(1); lwz 11,0x30(9); addi 10,10,32; cmpwi 11,0; beq 8f; ble 6f; lwz 9,0x44(30); rlwinm 11,11,2,0,29; addi 8,1,8; lwzx 10,9,11; add 9,9,11; lwz 0,0x8(9); lwz 11,0x4(9); stw 10,0x8(1); stw 0,0x8(8); stw 11,0x4(8); b 7f; 6:; lwz 9,0x18(30); addi 30,1,200; lwz 4,0x4(10); addi 9,9,-2; mr 3,30; xoris 9,9,32768; stw 9,0xe4(1); stw 28,0xe0(1); lfd f1,0xe0(1); fsub f1,f1,f31; frsp f1,f1; bl _s80069D10_6; lwz 10,0xc8(1); addi 11,1,8; lwz 0,0x8(30); lwz 9,0x4(30); stw 10,0x8(1); stw 0,0x8(11); stw 9,0x4(11); 7:; lis 9,-32707; lfs f13,0xc(1); lfs f0,0x4c98(9); fcmpu 0,f13,f0; ble 8f; lis 9,-32707; lfs f0,0x4c9c(9); fmuls f13,f13,f0; fdivs f13,f13,f30; stfs f13,0x0(29); 8:; lwz 3,0x8(31); mr 4,24; li 30,0; addi 3,3,820; bl _s80069D10_7; lwz 3,0x94(1); cmpwi 3,0; beq 9f; bl _s80069D10_8; stw 30,0x94(1); 9:; stw 30,0x94(1); b 11f; 10:; mr 3,26; mr 4,30; li 5,1; bl _s80069D10_9; 11:; lwz 0,0x3c(31); or 0,0,27; stw 0,0x3c(31); 12:; addi 3,1,164; bl _s80069D10_10; lwz 3,0x94(1); cmpwi 3,0; beq 13f; bl _s80069D10_11; li 0,0; stw 0,0x94(1); 13:; lwz 0,0x11c(1); mtspr 8,0; lmw 24,0xe8(1); lfd f30,0x108(1); lfd f31,0x110(1); addi 1,1,280"

extern "C" void _s80069D10_0();
extern "C" void _s80069D10_1();
extern "C" void _s80069D10_2();
extern "C" void _s80069D10_3();
extern "C" void _s80069D10_4();
extern "C" void _s80069D10_5();
extern "C" void _s80069D10_6();
extern "C" void _s80069D10_7();
extern "C" void _s80069D10_8();
extern "C" void _s80069D10_9();
extern "C" void _s80069D10_10();
extern "C" void _s80069D10_11();

struct SAnimator2 {
    void setMovementVelocityFromAnimation();
};

void SAnimator2::setMovementVelocityFromAnimation() {
}
