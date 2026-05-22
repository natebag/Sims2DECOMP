// 0x8008E4C0 ELiveMode::Update(void) (1364 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stmw 26,0x8(1); stw 0,0x2c(1); mr 26,3; bl _s8008E4C0_0; cmpwi 3,0; beq 31f; lwz 0,0x2c(26); cmpwi 0,0; bne 0f; lis 30,-32697; addi 30,30,24012; lwz 4,0x118(30); mr 3,30; bl _s8008E4C0_1; lis 9,-32697; mr 3,30; addi 9,9,23428; lwz 4,0x100(9); bl _s8008E4C0_2; 0:; lis 9,-32697; addi 30,9,23428; addi 31,30,244; lwz 0,0xc(31); cmpwi 0,0; beq 1f; bl _s8008E4C0_3; lwz 5,0xc(31); li 4,0; bl _s8008E4C0_4; 1:; addi 31,30,260; lwz 0,0xc(31); cmpwi 0,0; beq 2f; bl _s8008E4C0_5; lwz 5,0xc(31); li 4,1; bl _s8008E4C0_6; 2:; lwz 11,-21496(13); li 31,2; lwz 9,0x0(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; lis 9,-32697; addi 9,9,24012; addi 30,9,280; 3:; lwz 3,0x0(30); addi 30,30,4; bl _s8008E4C0_7; addic. 31,31,-1; bne 3b; lwz 0,0xc(26); cmpwi 0,0; beq 4f; mr 3,26; bl _s8008E4C0_8; 4:; lwz 3,-21472(13); bl _s8008E4C0_9; lis 30,-32697; addi 30,30,24012; lwz 3,0x10c(30); bl _s8008E4C0_10; lwz 0,0xc8(30); cmpwi 0,0; beq 8f; lwz 0,0x2c(26); cmpwi 0,0; bne 8f; lwz 11,-21496(13); lfs f31,-26800(13); cmpwi 11,0; beq 5f; lwz 9,0x0(11); lha 3,0x70(9); lwz 0,0x74(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 5f; lis 9,-32707; lfs f31,0x7df8(9); 5:; bl _s8008E4C0_11; li 31,0; fmr f1,f31; bl _s8008E4C0_12; bl _s8008E4C0_13; bl _s8008E4C0_14; bl _s8008E4C0_15; li 4,0; bl _s8008E4C0_16; mr. 3,3; beq 6f; lwz 0,0x8(3); cmpwi 0,0; beq 6f; li 31,1; 6:; bl _s8008E4C0_17; li 4,1; bl _s8008E4C0_18; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 7f; cmpwi 3,0; beq 7f; lwz 0,0x8(3); cmpwi 0,0; beq 7f; li 31,1; 7:; cmpwi 31,0; beq 8f; lwz 3,-21492(13); bl _s8008E4C0_19; 8:; lis 9,-32697; lwz 0,0x5c20(9); cmpwi 0,0; bne 31f; lwz 0,0x2c(26); cmpwi 0,0; bne 12f; lwz 3,-21496(13); lwz 9,0x0(3); lha 0,0x70(9); lwz 9,0x74(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 9f; lis 9,-32707; lfs f1,0x7df8(9); b 10f; 9:; lwz 3,-21496(13); lwz 9,0x0(3); lha 0,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; 10:; lis 9,-32697; lfs f0,-26800(13); lwz 0,0x5c70(9); fmuls f1,f1,f0; cmpwi 0,0; beq 11f; lis 9,-32707; lfs f0,0x7dfc(9); fmuls f1,f1,f0; 11:; stfs f1,-26796(13); b 13f; 12:; lis 9,-32707; lfs f0,0x7df8(9); stfs f0,-26796(13); 13:; lis 9,-32697; addi 3,9,24012; lwz 0,0xc8(3); cmpwi 0,0; beq 19f; lis 9,-32697; li 11,1; addi 9,9,23428; lwz 0,0xec(9); cmpwi 0,0; beq 14f; li 11,2; 14:; cmpwi 11,0; beq 18f; mr 27,3; addi 28,9,244; mr 31,11; addi 29,27,280; 15:; lwz 0,0x2c(26); li 30,0; cmpwi 0,0; bne 16f; lwz 30,0xc(28); 16:; cmpwi 30,0; beq 17f; lwz 4,0x0(29); mr 3,27; bl _s8008E4C0_20; mr 4,30; mr 3,27; bl _s8008E4C0_21; 17:; addi 29,29,4; addi 28,28,16; addic. 31,31,-1; bne 15b; 18:; lis 9,-32697; lwz 3,0x5e94(9); bl _s8008E4C0_22; 19:; lwz 11,-21496(13); lwz 9,0x0(11); lwz 0,0x154(9); lha 3,0x150(9); mtspr 8,0; add 3,11,3; blrl; lis 9,-32697; addi 31,9,24012; lwz 3,0x110(31); bl _s8008E4C0_23; lwz 11,-21496(13); li 4,39; lwz 9,0x0(11); lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,-1; bne 20f; lwz 9,0x148(31); lwz 3,0x0(9); bl _s8008E4C0_24; b 24f; 20:; cmpwi 3,0; blt 22f; extsh 0,3; cmpwi 0,1; ble 21f; li 3,1; 21:; extsh 0,3; b 23f; 22:; li 0,0; 23:; xori 3,0,1; subfic 9,3,0; adde 3,9,3; bl _s8008E4C0_25; 24:; lis 9,-32697; addi 30,9,24012; lwz 0,0x450(30); cmpwi 0,0; bne 25f; lwz 0,0x458(30); cmpwi 0,0; beq 29f; 25:; lis 9,-32697; addi 31,9,23428; lwz 11,0x44(31); cmpwi 11,0; beq 26f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 26:; lwz 11,-21476(13); li 29,0; stw 29,0x44(31); lwz 4,-32056(13); lwz 9,0x0(11); lwz 0,0x4c(9); lha 3,0x48(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21476(13); lwz 9,0x0(11); lwz 0,0x194(9); lha 3,0x190(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); lwz 4,-32056(13); lha 0,0x68(9); lwz 9,0x6c(9); lwz 5,-32040(13); add 3,3,0; mtspr 8,9; blrl; lwz 9,0xc8(30); cmpwi 9,0; beq 27f; lwz 0,0x54(9); stw 0,0x45c(30); 27:; lwz 31,0x450(30); cmpwi 31,0; beq 28f; stw 29,0x450(30); li 0,1; li 3,0; stw 0,0x24(26); bl _s8008E4C0_26; lwz 3,0x110(30); bl _s8008E4C0_27; b 29f; 28:; lwz 0,0x458(30); cmpwi 0,0; beq 29f; lwz 11,-21496(13); li 4,0; lwz 9,0x0(11); lwz 0,0x8c(9); lha 3,0x88(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21496(13); lwz 9,0x0(11); lwz 0,0x54(9); lha 3,0x50(9); mtspr 8,0; add 3,11,3; blrl; li 0,1; stw 0,0x28(26); stw 31,0x458(30); stw 31,0x450(30); 29:; lis 9,-32697; addi 31,9,24012; lwz 0,0x454(31); cmpwi 0,1; bne 31f; bl _s8008E4C0_28; cmpwi 3,0; bne 30f; mr 3,26; bl _s8008E4C0_29; b 31f; 30:; lwz 9,-32160(13); lwz 0,0xb4(9); andi. 9,0,4; beq 31f; li 0,0; stw 0,0x454(31); 31:; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x8(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s8008E4C0_0();
extern "C" void _s8008E4C0_1();
extern "C" void _s8008E4C0_2();
extern "C" void _s8008E4C0_3();
extern "C" void _s8008E4C0_4();
extern "C" void _s8008E4C0_5();
extern "C" void _s8008E4C0_6();
extern "C" void _s8008E4C0_7();
extern "C" void _s8008E4C0_8();
extern "C" void _s8008E4C0_9();
extern "C" void _s8008E4C0_10();
extern "C" void _s8008E4C0_11();
extern "C" void _s8008E4C0_12();
extern "C" void _s8008E4C0_13();
extern "C" void _s8008E4C0_14();
extern "C" void _s8008E4C0_15();
extern "C" void _s8008E4C0_16();
extern "C" void _s8008E4C0_17();
extern "C" void _s8008E4C0_18();
extern "C" void _s8008E4C0_19();
extern "C" void _s8008E4C0_20();
extern "C" void _s8008E4C0_21();
extern "C" void _s8008E4C0_22();
extern "C" void _s8008E4C0_23();
extern "C" void _s8008E4C0_24();
extern "C" void _s8008E4C0_25();
extern "C" void _s8008E4C0_26();
extern "C" void _s8008E4C0_27();
extern "C" void _s8008E4C0_28();
extern "C" void _s8008E4C0_29();
extern "C" void f_8008E4C0() {}
