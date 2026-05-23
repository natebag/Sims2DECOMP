// 0x8006AFC4 SAnimator2::UpdateNPCAutoRun(void) (1292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-280(1); mfspr 0,8; stfd f30,0x108(1); stfd f31,0x110(1); stmw 24,0xe8(1); stw 0,0x11c(1); mr 31,3; li 30,0; lwz 0,0x600(31); cmpwi 0,0; beq 1f; lbz 0,0x5f9(31); cmpwi 0,0; bne 1f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x1a0(9); lwz 9,0x1a4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0f; lwz 0,0x108(31); cmpwi 0,1; beq 1f; li 0,1; li 30,1; stw 0,0x108(31); b 1f; 0:; lwz 0,0x108(31); cmpwi 0,0; beq 1f; stw 30,0x108(31); li 30,1; 1:; cmpwi 30,1; bne 28f; addi 3,1,24; bl _s8006AFC4_0; lwz 0,0x108(31); cmpwi 0,2; bne 2f; addi 29,31,168; li 27,4; b 6f; 2:; cmpwi 0,3; bne 3f; addi 29,31,172; li 27,8; b 6f; 3:; cmpwi 0,1; beq 4f; cmpwi 0,8; bne 5f; 4:; addi 29,31,160; li 27,2; b 6f; 5:; addi 29,31,156; li 27,1; 6:; lwz 0,0x3c(31); lis 25,-32707; and. 24,0,27; bne 14f; addi 4,1,216; mr 3,31; bl _s8006AFC4_1; lis 30,-32693; lwz 9,0xd8(1); addi 3,30,11064; lwz 4,0x0(9); bl _s8006AFC4_2; cmpwi 3,0; beq 14f; lwz 9,0xd8(1); addi 26,30,11064; mr 3,26; li 5,0; lwz 4,0x0(9); li 6,0; bl _s8006AFC4_3; mr. 30,3; beq 14f; lwz 11,0x18(30); lis 28,17200; mr 8,10; addi 0,11,-1; lis 9,-32707; xoris 0,0,32768; addi 11,11,-2; stw 0,0xe4(1); xoris 11,11,32768; lfd f31,0x4d48(9); stw 28,0xe0(1); lfs f11,0x64(30); lfd f13,0xe0(1); stw 11,0xe4(1); fsub f13,f13,f31; lfs f10,0x4d40(25); stw 28,0xe0(1); frsp f12,f13; fmr f13,f12; lfd f0,0xe0(1); fdivs f30,f13,f11; fsub f0,f0,f31; frsp f0,f0; fdivs f0,f0,f12; fmuls f30,f30,f0; fcmpu 0,f30,f10; beq 12f; lwz 3,0x94(1); cmpwi 3,0; beq 7f; bl _s8006AFC4_4; stw 24,0x94(1); 7:; lwz 3,0x8(31); addi 4,1,24; stw 30,0x94(1); addi 3,3,820; bl _s8006AFC4_5; lwz 9,0x34(30); lwz 10,0xb0(1); lwz 9,0x30(9); addi 10,10,32; cmpwi 9,0; beq 10f; ble 8f; lwz 11,0x44(30); rlwinm 9,9,2,0,29; add 10,11,9; lwzx 8,11,9; lwz 7,0x8(10); lwz 0,0x4(10); stw 8,0x8(1); stw 0,0xc(1); stw 7,0x10(1); b 9f; 8:; lwz 9,0x18(30); lwz 4,0x4(10); addi 3,1,200; addi 9,9,-2; xoris 9,9,32768; stw 9,0xe4(1); stw 28,0xe0(1); lfd f1,0xe0(1); fsub f1,f1,f31; frsp f1,f1; bl _s8006AFC4_6; lwz 0,0xc8(1); lwz 9,0xcc(1); lwz 11,0xd0(1); stw 0,0x8(1); stw 9,0xc(1); stw 11,0x10(1); 9:; lis 9,-32707; lfs f13,0xc(1); lfs f0,0x4d50(9); fcmpu 0,f13,f0; ble 10f; lis 9,-32707; lfs f0,0x4d54(9); fmuls f13,f13,f0; fdivs f13,f13,f30; stfs f13,0x0(29); 10:; lwz 3,0x8(31); addi 4,1,24; li 30,0; addi 3,3,820; bl _s8006AFC4_7; lwz 3,0x94(1); cmpwi 3,0; beq 11f; bl _s8006AFC4_8; stw 30,0x94(1); 11:; stw 30,0x94(1); b 13f; 12:; mr 3,26; mr 4,30; li 5,1; bl _s8006AFC4_9; 13:; lwz 0,0x3c(31); or 0,0,27; stw 0,0x3c(31); 14:; addi 3,1,164; bl _s8006AFC4_10; lwz 3,0x94(1); cmpwi 3,0; beq 15f; bl _s8006AFC4_11; li 0,0; stw 0,0x94(1); 15:; lwz 0,0x108(31); addi 30,1,220; cmpwi 0,2; bne 16f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x218(9); lwz 9,0x21c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 21f; lwz 3,0x4(31); mr 5,30; li 4,18; b 25f; 16:; cmpwi 0,3; bne 17f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x218(9); lwz 9,0x21c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 21f; b 24f; 17:; cmpwi 0,1; beq 18f; cmpwi 0,8; bne 20f; 18:; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x218(9); lwz 9,0x21c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 19f; lwz 3,0x4(31); mr 5,30; li 4,73; bl _s8006AFC4_12; b 27f; 19:; lwz 3,0x4(31); mr 5,30; li 4,21; bl _s8006AFC4_13; b 27f; 20:; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x218(9); lwz 9,0x21c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 22f; 21:; lwz 3,0x4(31); mr 5,30; li 4,74; bl _s8006AFC4_14; b 27f; 22:; lbz 0,0x5f9(31); cmpwi 0,5; beq 23f; cmpwi 0,9; beq 24f; b 26f; 23:; lwz 3,0x4(31); mr 5,30; li 4,18; b 25f; 24:; lwz 3,0x4(31); mr 5,30; li 4,59; 25:; bl _s8006AFC4_15; lwz 9,0xdc(1); lis 3,-32693; addi 3,3,11064; lwz 4,0x0(9); bl _s8006AFC4_16; cmpwi 3,0; bne 27f; lwz 3,0x4(31); mr 5,30; li 4,20; bl _s8006AFC4_17; b 27f; 26:; lwz 3,0x4(31); mr 5,30; li 4,20; bl _s8006AFC4_18; 27:; lwz 3,0x8(31); lis 4,1; addi 3,3,820; bl _s8006AFC4_19; lwz 9,0xdc(1); fmr f31,f1; lwz 3,0x8(31); li 7,0; lwz 5,0x0(9); li 4,2; lfs f1,-32328(13); li 6,2; addi 3,3,820; bl _s8006AFC4_20; lwz 3,0x8(31); fmr f1,f31; lis 4,1; li 5,1; addi 3,3,820; bl _s8006AFC4_21; li 9,0; lwz 0,0x61c(31); stw 9,0xc8(31); lis 11,-32707; lwz 9,0xdc(1); oris 0,0,1; lfs f0,0x4d40(11); stw 0,0x61c(31); stfs f0,0xd0(31); stw 9,0xd4(31); 28:; lwz 0,0x11c(1); mtspr 8,0; lmw 24,0xe8(1); lfd f30,0x108(1); lfd f31,0x110(1); addi 1,1,280"

extern "C" void _s8006AFC4_0();
extern "C" void _s8006AFC4_1();
extern "C" void _s8006AFC4_2();
extern "C" void _s8006AFC4_3();
extern "C" void _s8006AFC4_4();
extern "C" void _s8006AFC4_5();
extern "C" void _s8006AFC4_6();
extern "C" void _s8006AFC4_7();
extern "C" void _s8006AFC4_8();
extern "C" void _s8006AFC4_9();
extern "C" void _s8006AFC4_10();
extern "C" void _s8006AFC4_11();
extern "C" void _s8006AFC4_12();
extern "C" void _s8006AFC4_13();
extern "C" void _s8006AFC4_14();
extern "C" void _s8006AFC4_15();
extern "C" void _s8006AFC4_16();
extern "C" void _s8006AFC4_17();
extern "C" void _s8006AFC4_18();
extern "C" void _s8006AFC4_19();
extern "C" void _s8006AFC4_20();
extern "C" void _s8006AFC4_21();

struct SAnimator2 {
    void UpdateNPCAutoRun();
};

void SAnimator2::UpdateNPCAutoRun() {
}
