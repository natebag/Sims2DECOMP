// 0x8006BD5C SAnimator2::selectIdleOverlay(void) (652 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f31,0x30(1); stmw 30,0x28(1); stw 0,0x3c(1); mr 31,3; lwz 0,0x61c(31); andi. 9,0,8192; bne 12f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x1f0(9); lwz 9,0x1f4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,1; beq 12f; lwz 0,0x2c(31); cmpwi 0,16; beq 12f; mr 3,31; bl _s8006BD5C_0; cmpwi 3,0; bne 12f; lwz 0,0x61c(31); andis. 9,0,1024; bne 12f; andi. 9,0,4096; bne 12f; bl _s8006BD5C_1; lis 0,20971; srawi 9,3,31; ori 0,0,34079; mulhw 0,3,0; srawi 0,0,5; subf 0,9,0; mulli 0,0,100; subf 3,0,3; cmpwi 3,49; bgt 12f; lwz 11,0x61c(31); li 0,20; stw 0,0x8(1); li 30,19; ori 11,11,4096; stw 11,0x61c(31); lwz 10,0x4(31); lwz 9,0x4(10); lha 3,0x170(9); lwz 0,0x174(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,1; beq 0f; lwz 0,0x61c(31); andi. 9,0,2048; bne 0f; lwz 0,0x620(31); andi. 9,0,512; beq 1f; 0:; lwz 0,0x8(1); stw 0,0xc(1); b 2f; 1:; lwz 9,0x8(1); addi 9,9,20; stw 9,0xc(1); 2:; lwz 9,0xc(1); addi 11,9,60; addi 0,9,20; addi 9,9,40; stw 0,0x10(1); stw 9,0x14(1); stw 11,0x18(1); bl _s8006BD5C_2; lwz 11,0x18(1); addi 8,1,8; li 10,0; addi 5,1,32; divw 0,3,11; lwzx 9,8,10; mullw 0,0,11; subf 3,0,3; cmpw 3,9; ble 4f; mr 9,8; 3:; addi 10,10,1; cmpwi 10,4; bgt 4f; lwzu 0,0x4(9); cmpw 3,0; bgt 3b; 4:; cmpwi 10,2; beq 8f; bgt 5f; cmpwi 10,0; beq 6f; cmpwi 10,1; beq 7f; b 11f; 5:; cmpwi 10,3; beq 9f; cmpwi 10,4; beq 10f; b 11f; 6:; li 30,19; b 11f; 7:; li 30,24; b 11f; 8:; li 30,25; b 11f; 9:; li 30,71; b 11f; 10:; li 30,72; 11:; lwz 3,0x4(31); mr 4,30; bl _s8006BD5C_3; lwz 5,0x20(1); cmpwi 5,0; beq 12f; lwz 3,0x8(31); lis 9,-32707; lwz 5,0x0(5); li 4,256; lfs f1,0x4dc0(9); addi 3,3,820; li 6,-1; li 7,0; bl _s8006BD5C_4; lfs f31,-32336(13); mr. 30,3; beq 12f; lis 9,-32707; lwz 3,0x8(31); lfs f1,0x4dc4(9); li 5,1; addi 3,3,820; mr 4,30; bl _s8006BD5C_5; lwz 3,0x8(31); lis 5,-32688; addi 5,5,-20000; mr 4,30; addi 3,3,820; bl _s8006BD5C_6; lwz 3,0x8(31); lis 9,-32707; lis 11,-32707; lfs f1,0x4dc8(9); lfs f3,0x4dcc(11); addi 3,3,820; fmr f2,f31; mr 4,30; bl _s8006BD5C_7; li 0,1; stb 0,0xd(30); 12:; lwz 0,0x3c(1); mtspr 8,0; lmw 30,0x28(1); lfd f31,0x30(1); addi 1,1,56"

extern "C" void _s8006BD5C_0();
extern "C" void _s8006BD5C_1();
extern "C" void _s8006BD5C_2();
extern "C" void _s8006BD5C_3();
extern "C" void _s8006BD5C_4();
extern "C" void _s8006BD5C_5();
extern "C" void _s8006BD5C_6();
extern "C" void _s8006BD5C_7();

struct SAnimator2 {
    void selectIdleOverlay();
};

void SAnimator2::selectIdleOverlay() {
}
