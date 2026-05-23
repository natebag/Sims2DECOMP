// 0x800632EC SAnimator2::selectRandomIdle(void) (752 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; li 29,70; bl _s800632EC_0; mr. 30,3; beq 11f; lbz 0,0x5fb(31); cmpwi 0,0; beq 0f; mr 3,31; bl _s800632EC_1; 0:; lbz 0,0x5fa(31); cmpwi 0,0; beq 1f; cmpw 0,30; beq 1f; mr 3,31; bl _s800632EC_2; 1:; rlwinm 0,30,0,24,31; stb 30,0x5fa(31); cmpwi 0,8; beq 7f; bgt 2f; cmpwi 0,5; beq 4f; cmpwi 0,7; beq 6f; b 10f; 2:; cmpwi 0,14; beq 8f; bgt 3f; cmpwi 0,9; beq 5f; b 10f; 3:; cmpwi 0,15; beq 9f; b 10f; 4:; li 29,60; b 24f; 5:; li 29,58; b 24f; 6:; li 29,62; b 24f; 7:; li 29,63; b 24f; 8:; li 29,64; b 24f; 9:; li 29,61; b 24f; 10:; li 29,3; b 24f; 11:; mr 3,31; bl _s800632EC_3; lwz 0,0x61c(31); lwz 9,0x8(31); rlwinm 0,0,0,6,4; stw 0,0x61c(31); addi 11,9,820; lwz 9,0x8(11); cmpwi 9,-1; beq 12f; mulli 9,9,176; lwz 0,0x44(11); add 9,9,0; lwz 9,0x30(9); b 13f; 12:; li 9,0; 13:; andi. 0,9,33; bne 14f; mr 3,31; bl _s800632EC_4; b 24f; 14:; lbz 4,0x5fb(31); cmpwi 4,0; beq 17f; lwz 3,0x4(31); addi 5,1,8; lis 30,-32693; bl _s800632EC_5; lwz 9,0x8(1); addi 3,30,11064; lwz 4,0x0(9); bl _s800632EC_6; cmpwi 3,0; beq 16f; lwz 0,0x61c(31); andis. 9,0,8; beq 15f; lwz 9,0x8(1); addi 3,30,11064; li 5,1; lwz 4,0x0(9); bl _s800632EC_7; 15:; lwz 0,0x61c(31); li 9,0; lbz 29,0x5fb(31); li 11,0; oris 0,0,1024; stb 9,0x5fb(31); rlwinm 0,0,0,13,11; stw 11,0x11c(31); stw 0,0x61c(31); b 24f; 16:; lwz 0,0x61c(31); andis. 9,0,8; bne 23f; lwz 9,0x8(1); b 22f; 17:; lwz 0,0x11c(31); cmpwi 0,3; ble 23f; bl _s800632EC_8; lis 0,-21846; rlwinm 3,3,0,24,31; ori 0,0,43691; mulhwu 0,3,0; rlwinm 0,0,31,1,31; rlwinm 9,0,1,0,30; add 9,9,0; subf 3,9,3; rlwinm 0,3,0,24,31; stb 3,0x5fb(31); cmpwi 0,1; beq 18f; cmpwi 0,0; bne 20f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x200(9); lwz 9,0x204(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 19f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x170(9); lwz 9,0x174(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 18f; lwz 0,0x61c(31); andi. 9,0,2048; bne 18f; lwz 0,0x620(31); andi. 9,0,512; beq 19f; 18:; li 0,68; b 21f; 19:; lbz 0,0x5fb(31); cmpwi 0,0; li 0,67; beq 21f; 20:; li 0,69; 21:; stb 0,0x5fb(31); lwz 3,0x4(31); addi 5,1,12; lbz 4,0x5fb(31); lis 30,-32693; bl _s800632EC_9; lwz 9,0xc(1); addi 3,30,11064; lwz 4,0x0(9); bl _s800632EC_10; cmpwi 3,0; bne 23f; lwz 9,0xc(1); 22:; addi 3,30,11064; lwz 4,0x0(9); bl _s800632EC_11; lwz 0,0x61c(31); oris 0,0,8; stw 0,0x61c(31); 23:; lwz 9,0x11c(31); addi 9,9,1; stw 9,0x11c(31); 24:; mr 3,29; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

extern "C" void _s800632EC_0();
extern "C" void _s800632EC_1();
extern "C" void _s800632EC_2();
extern "C" void _s800632EC_3();
extern "C" void _s800632EC_4();
extern "C" void _s800632EC_5();
extern "C" void _s800632EC_6();
extern "C" void _s800632EC_7();
extern "C" void _s800632EC_8();
extern "C" void _s800632EC_9();
extern "C" void _s800632EC_10();
extern "C" void _s800632EC_11();

struct SAnimator2 {
    void selectRandomIdle();
};

void SAnimator2::selectRandomIdle() {
}
