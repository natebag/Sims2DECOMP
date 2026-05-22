// 0x800942F4 PreGameState::Update(float) (1504 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 26,0x50(1); stw 0,0x6c(1); mr 29,3; lwz 31,0x28(29); cmpwi 31,0; beq 12f; lis 9,-32706; lwz 27,0xc(29); lfs f0,-31380(9); lis 3,-32697; addi 3,3,23428; li 28,0; stfs f0,0xc(1); li 30,1; stfs f0,0x8(1); lis 26,-32697; bl _s800942F4_0; cmpwi 27,0; beq 0f; cmpwi 27,1; beq 5f; b 7f; 0:; addi 31,26,23428; lis 3,-32697; addi 3,3,-7672; stw 30,0xe4(31); li 4,9; bl _s800942F4_1; lwz 0,0x84(31); lis 9,-32697; addi 9,9,24012; cmpwi 0,0; stb 28,0xb8(9); stb 28,0xb9(9); beq 4f; lwz 0,0xec(31); stw 30,0x448(9); cmpwi 0,0; beq 1f; stw 30,0x44c(9); b 2f; 1:; stw 28,0x44c(9); 2:; lis 9,-32697; lwz 0,0x5c74(9); cmpwi 0,0; beq 3f; lis 3,-32697; addi 3,3,24012; bl _s800942F4_2; 3:; bl _s800942F4_3; b 6f; 4:; lwz 0,0xe8(31); cmpwi 0,0; bne 6f; lwz 11,-21476(13); cmpwi 11,0; beq 6f; lwz 9,0x0(11); li 4,1; lha 3,0x120(9); lwz 0,0x124(9); add 3,11,3; mtspr 8,0; blrl; mr. 3,3; beq 6f; lwz 0,0x34(3); andi. 9,0,16; beq 6f; stw 28,0x2c(29); stw 28,0xe4(31); b 6f; 5:; addi 3,1,16; bl _s800942F4_4; addi 3,1,16; li 4,16; bl _s800942F4_5; lwz 30,-21480(13); addi 3,1,16; li 4,2; bl _s800942F4_6; cmpwi 30,0; beq 9f; 6:; lwz 9,0xc(29); addi 9,9,1; stw 9,0xc(29); b 9f; 7:; lis 9,-32697; lwz 0,0x5c6c(9); cmpwi 0,0; beq 8f; lis 9,-32706; mr 3,29; lfs f1,-31380(9); li 4,9; bl _s800942F4_7; 8:; li 0,0; li 28,1; stw 0,0x28(29); 9:; lwz 6,0xc(29); lis 3,-32697; lis 31,-32706; addi 3,3,23428; mr 5,27; addi 4,31,-31432; bl _s800942F4_8; cmpwi 28,0; beq 29f; addi 3,26,23428; lwz 0,0x84(3); cmpwi 0,0; beq 10f; lis 5,-32706; addi 4,31,-31432; addi 5,5,-31408; b 11f; 10:; lis 5,-32706; addi 4,31,-31432; addi 5,5,-31396; 11:; li 6,0; bl _s800942F4_9; b 29f; 12:; lwz 30,0x24(29); cmpwi 30,0; beq 14f; bl _s800942F4_10; cmpwi 3,0; bne 13f; li 3,4; bl _s800942F4_11; b 29f; 13:; lis 9,-32697; li 0,-1; lis 30,-32697; stw 0,0x6230(9); addi 3,30,23428; stw 31,-28408(13); stw 31,-28404(13); bl _s800942F4_12; addi 3,30,23428; bl _s800942F4_13; addi 3,30,23428; bl _s800942F4_14; lis 9,-32706; mr 3,29; lfs f1,-31380(9); li 4,13; bl _s800942F4_15; b 29f; 14:; lwz 0,0x2c(29); cmpwi 0,0; bne 15f; lwz 31,0x20(29); cmpwi 31,0; beq 25f; 15:; lwz 9,0x8(29); lwz 31,0x90(9); cmpwi 31,0; beq 18f; stw 30,0x90(9); cmpwi 31,1; bne 17f; lwz 0,0x1c(29); cmpwi 0,0; beq 16f; lwz 11,-21476(13); lwz 9,0x0(11); lwz 0,0x164(9); lha 3,0x160(9); mtspr 8,0; add 3,11,3; blrl; stw 30,0x1c(29); lis 3,-32706; addi 3,3,-31448; li 4,0; bl _s800942F4_16; lwz 0,0x20(29); cmpwi 0,0; beq 29f; 16:; mr 3,29; li 4,1; bl _s800942F4_17; b 29f; 17:; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 28f; lwz 0,0x1c(29); cmpwi 0,0; bne 28f; lis 3,-32706; li 4,1; addi 3,3,-31448; bl _s800942F4_18; b 29f; 18:; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 21f; lis 30,-32706; addi 3,30,-31448; bl _s800942F4_19; cmpwi 3,0; bne 19f; lwz 11,-21476(13); stw 31,-28408(13); stw 31,-28404(13); cmpwi 11,0; beq 23f; lwz 9,0x0(11); li 4,1; lha 3,0x120(9); lwz 0,0x124(9); add 3,11,3; mtspr 8,0; blrl; mr. 11,3; beq 23f; lwz 0,0x34(11); li 4,-1; lwz 9,0x0(11); ori 0,0,16; stw 0,0x34(11); lha 3,0xb0(9); lwz 0,0xb4(9); add 3,11,3; mtspr 8,0; blrl; b 23f; 19:; addi 3,30,-31448; bl _s800942F4_20; cmpwi 3,1; bne 29f; mr 3,29; bl _s800942F4_21; cmpwi 3,0; beq 29f; stw 31,-28408(13); li 3,1; stw 31,-28404(13); bl _s800942F4_22; lwz 11,-21476(13); cmpwi 11,0; beq 20f; lwz 9,0x0(11); li 4,1; lha 3,0x120(9); lwz 0,0x124(9); add 3,11,3; mtspr 8,0; blrl; mr. 3,3; beq 20f; lwz 0,0x34(3); ori 0,0,32; stw 0,0x34(3); 20:; lwz 3,-21492(13); li 4,3; bl _s800942F4_23; mr 3,29; li 4,11; bl _s800942F4_24; li 0,1; stw 0,0x1c(29); b 29f; 21:; stw 0,-28408(13); li 3,1; stw 0,-28404(13); bl _s800942F4_25; lwz 11,-21476(13); cmpwi 11,0; beq 22f; lwz 9,0x0(11); li 4,1; lha 3,0x120(9); lwz 0,0x124(9); add 3,11,3; mtspr 8,0; blrl; mr. 11,3; beq 22f; lwz 0,0x34(11); li 4,-1; lwz 9,0x0(11); ori 0,0,16; stw 0,0x34(11); lha 3,0xb0(9); lwz 0,0xb4(9); add 3,11,3; mtspr 8,0; blrl; 22:; lwz 3,-26564(13); lwz 9,0x0(3); lha 0,0x48(9); lwz 9,0x4c(9); add 3,3,0; mtspr 8,9; blrl; 23:; lwz 3,-24508(13); cmpwi 3,0; beq 24f; addi 3,3,48; li 4,32; bl _s800942F4_26; lwz 3,-24508(13); li 4,32; addi 3,3,48; bl _s800942F4_27; 24:; lwz 3,-21492(13); li 4,3; bl _s800942F4_28; mr 3,29; li 4,10; bl _s800942F4_29; b 29f; 25:; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 28f; mr 3,29; bl _s800942F4_30; cmpwi 3,0; beq 28f; lis 3,-32706; li 4,1; addi 3,3,-31448; bl _s800942F4_31; stw 31,-28408(13); li 3,1; stw 31,-28404(13); bl _s800942F4_32; lwz 11,-21476(13); cmpwi 11,0; beq 26f; lwz 9,0x0(11); li 4,1; lha 3,0x120(9); lwz 0,0x124(9); add 3,11,3; mtspr 8,0; blrl; mr. 3,3; beq 26f; lwz 0,0x34(3); ori 0,0,32; stw 0,0x34(3); 26:; lwz 3,-24508(13); cmpwi 3,0; beq 27f; addi 3,3,48; li 4,32; bl _s800942F4_33; lwz 3,-24508(13); li 4,32; addi 3,3,48; bl _s800942F4_34; 27:; lwz 3,-21492(13); li 4,3; bl _s800942F4_35; mr 3,29; li 4,11; bl _s800942F4_36; li 0,1; stw 0,0x20(29); stw 0,0x1c(29); b 29f; 28:; li 0,1; stw 0,0x24(29); 29:; lwz 0,0x6c(1); mtspr 8,0; lmw 26,0x50(1); addi 1,1,104"
extern "C" void _s800942F4_0();
extern "C" void _s800942F4_1();
extern "C" void _s800942F4_2();
extern "C" void _s800942F4_3();
extern "C" void _s800942F4_4();
extern "C" void _s800942F4_5();
extern "C" void _s800942F4_6();
extern "C" void _s800942F4_7();
extern "C" void _s800942F4_8();
extern "C" void _s800942F4_9();
extern "C" void _s800942F4_10();
extern "C" void _s800942F4_11();
extern "C" void _s800942F4_12();
extern "C" void _s800942F4_13();
extern "C" void _s800942F4_14();
extern "C" void _s800942F4_15();
extern "C" void _s800942F4_16();
extern "C" void _s800942F4_17();
extern "C" void _s800942F4_18();
extern "C" void _s800942F4_19();
extern "C" void _s800942F4_20();
extern "C" void _s800942F4_21();
extern "C" void _s800942F4_22();
extern "C" void _s800942F4_23();
extern "C" void _s800942F4_24();
extern "C" void _s800942F4_25();
extern "C" void _s800942F4_26();
extern "C" void _s800942F4_27();
extern "C" void _s800942F4_28();
extern "C" void _s800942F4_29();
extern "C" void _s800942F4_30();
extern "C" void _s800942F4_31();
extern "C" void _s800942F4_32();
extern "C" void _s800942F4_33();
extern "C" void _s800942F4_34();
extern "C" void _s800942F4_35();
extern "C" void _s800942F4_36();
extern "C" void f_800942F4() {}
