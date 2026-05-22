// 0x801A9A64 CSPTarget::SetupCareer(cXPerson (1596 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-776(1); mfspr 0,8; stmw 19,0x2d4(1); stw 0,0x30c(1); mr 25,4; mr 31,3; lwz 9,0x4(25); li 4,56; lwz 29,-21412(13); addi 20,31,180; lha 3,0x138(9); addi 19,31,192; lwz 9,0x13c(9); lwz 30,0x0(29); add 3,25,3; mtspr 8,9; lha 0,0x20(30); addi 30,30,32; add 29,29,0; blrl; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; li 10,3; mr 28,3; mtspr 9,10; li 11,-1; li 0,0; addi 9,31,204; 0:; stw 11,-24(9); stw 0,-12(9); stw 0,0x0(9); addi 9,9,4; bdnz 0b; li 0,0; cmpwi 28,0; stw 0,0xd8(31); stw 0,0xdc(31); beq 27f; lwz 9,0x4(25); li 4,57; addi 30,1,712; addi 27,1,520; lwz 0,0x13c(9); addi 23,31,156; lha 3,0x138(9); addi 22,31,160; mtspr 8,0; addi 24,31,164; add 3,25,3; addi 26,31,172; blrl; lis 9,-32705; lwz 0,0x0(28); lwz 11,0x6a2c(9); mr 21,3; li 7,-1; li 8,0; cmpw 11,0; bne 1f; li 7,0; b 2f; 1:; addi 8,8,1; cmpwi 8,10; bgt 2f; lis 9,-32705; rlwinm 10,8,2,0,29; addi 9,9,27180; lwz 11,0x0(28); lwzx 0,9,10; cmpw 0,11; bne 1b; mr 7,8; 2:; cmpwi 7,-1; beq 3f; lis 9,-32705; lwz 10,0x0(31); addi 9,9,27224; rlwinm 0,7,2,0,29; lis 11,-32705; lwzx 5,9,0; addi 4,11,-4560; cmpwi 10,0; beq 4f; lwz 3,0x1c(31); cmpwi 3,0; beq 4f; lwz 6,0x7c(31); li 7,0; bl _s801A9A64_0; b 4f; 3:; bl _s801A9A64_1; lwz 0,0x0(31); lis 9,-32705; mr 5,3; addi 4,9,-4560; cmpwi 0,0; beq 4f; lwz 3,0x1c(31); cmpwi 3,0; beq 4f; lwz 6,0x7c(31); li 7,0; bl _s801A9A64_2; 4:; mulli 0,21,112; lwz 9,0x4(28); li 4,0; add 9,9,0; mr 29,0; lwz 9,0x6c(9); cmpwi 9,0; beq 5f; lwz 4,0x0(9); 5:; mr 3,23; bl _s801A9A64_3; lwz 9,0x8(28); li 4,0; cmpwi 9,0; beq 6f; lwz 4,0x0(9); 6:; mr 3,22; bl _s801A9A64_4; lwz 9,0x4(25); lha 3,0x200(9); lwz 0,0x204(9); add 3,25,3; mtspr 8,0; blrl; cmpwi 3,0; beq 8f; lwz 9,0x4(28); li 4,0; add 9,9,29; lwz 9,0x58(9); cmpwi 9,0; beq 7f; lwz 4,0x0(9); 7:; mr 3,24; bl _s801A9A64_5; b 10f; 8:; lwz 9,0x4(28); li 4,0; add 9,9,29; lwz 9,0x5c(9); cmpwi 9,0; beq 9f; lwz 4,0x0(9); 9:; mr 3,24; bl _s801A9A64_6; 10:; lwz 9,0x4(28); lis 4,-32697; lis 5,-32705; addi 4,4,24012; add 9,9,29; mr 3,30; lwz 0,0x44(9); addi 5,5,-4544; stw 0,0xb0(31); crxor 6,6,6; bl _s801A9A64_7; lwz 9,0x2c8(1); li 4,0; cmpwi 9,0; beq 11f; lwz 4,0x0(9); 11:; addi 3,1,8; bl _s801A9A64_8; lis 4,-32705; addi 3,1,8; addi 4,4,-4536; bl _s801A9A64_9; cmpwi 3,0; li 0,1; bne 12f; li 0,0; 12:; cmpwi 0,0; beq 13f; lwz 9,0x4(28); lis 4,-32705; addi 4,4,-4520; mr 3,27; add 9,9,29; lwz 5,0x48(9); addi 29,1,584; lwz 6,0x4c(9); crxor 6,6,6; bl _s801A9A64_10; mr 3,27; bl _s801A9A64_11; mr 30,3; mr 5,29; mr 4,30; mr 3,27; bl _s801A9A64_12; add 30,30,30; li 0,0; sthx 0,29,30; mr 3,26; mr 4,29; bl _s801A9A64_13; b 19f; 13:; lwz 9,0x4(28); lis 0,10922; ori 0,0,43691; add 9,9,29; lwz 3,0x48(9); mulhw 0,3,0; srawi 9,3,31; cmpwi 7,3,12; mfcr 30; rlwinm 30,30,29,31,31; srawi 0,0,1; subf 0,9,0; mulli 0,0,12; subf. 3,0,3; bne 14f; li 3,12; 14:; mr 4,27; bl _s801A9A64_14; mr 3,26; mr 4,27; bl _s801A9A64_15; cmpwi 30,0; beq 15f; lis 4,-32705; mr 3,26; addi 4,4,-4504; bl _s801A9A64_16; b 16f; 15:; lis 4,-32705; mr 3,26; addi 4,4,-4488; bl _s801A9A64_17; 16:; lwz 9,0x4(28); lis 0,10922; ori 0,0,43691; add 9,9,29; lwz 3,0x4c(9); mulhw 0,3,0; srawi 9,3,31; cmpwi 7,3,12; mfcr 30; rlwinm 30,30,29,31,31; srawi 0,0,1; subf 0,9,0; mulli 0,0,12; subf. 3,0,3; bne 17f; li 3,12; 17:; mr 4,27; bl _s801A9A64_18; mr 4,27; mr 3,26; bl _s801A9A64_19; cmpwi 30,0; beq 18f; lis 4,-32705; mr 3,26; addi 4,4,-4472; bl _s801A9A64_20; b 19f; 18:; lis 4,-32705; mr 3,26; addi 4,4,-4464; bl _s801A9A64_21; 19:; lwz 9,0x4(25); lwz 29,-21476(13); lha 3,0x1b0(9); lwz 9,0x1b4(9); lwz 30,0x0(29); add 3,25,3; mtspr 8,9; lha 0,0xb8(30); addi 30,30,184; add 29,29,0; blrl; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; mr. 3,3; beq 20f; bl _s801A9A64_22; stw 3,0xd8(31); 20:; lwz 9,0x4(28); addi 3,21,1; li 11,0; cmpwi 7,9,0; beq cr7,21f; lwz 11,-4(9); 21:; addi 0,11,-1; cmpw 3,0; ble 23f; li 3,0; beq cr7,22f; lwz 3,-4(9); 22:; addi 3,3,-1; 23:; mulli 3,3,112; li 0,10; mtspr 9,0; lis 5,20971; mr 30,20; mr 4,19; li 10,0; ori 5,5,34079; li 7,0; mr 6,3; li 8,0; 24:; cmpwi 7,10,0; bne cr7,25f; lwz 9,0x4(28); add 9,9,6; lwzx 0,9,10; stw 0,0xdc(31); 25:; lwz 9,0x4(28); add 9,9,6; lwzx 0,9,7; cmpwi 0,0; beq 26f; beq cr7,26f; stwx 10,8,30; lwz 9,0x4(28); add 9,9,3; lwzx 11,9,7; mulhw 0,11,5; srawi 11,11,31; srawi 0,0,5; subf 0,11,0; stwx 0,8,4; addi 8,8,4; 26:; addi 7,7,4; addi 10,10,1; bdnz 24b; mr 3,31; bl _s801A9A64_23; b 32f; 27:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-4456; addi 3,1,716; addi 30,31,160; crxor 6,6,6; bl _s801A9A64_24; lwz 9,0x2cc(1); li 4,0; cmpwi 9,0; beq 28f; lwz 4,0x0(9); 28:; mr 3,30; bl _s801A9A64_25; lis 30,-32705; li 0,-1; addi 4,30,-8284; stw 0,0xb0(31); addi 3,31,164; bl _s801A9A64_26; addi 4,30,-8284; addi 3,31,172; bl _s801A9A64_27; bl _s801A9A64_28; lwz 0,0x0(31); lis 9,-32705; mr 5,3; addi 4,9,-4560; cmpwi 0,0; beq 29f; lwz 3,0x1c(31); cmpwi 3,0; beq 29f; lwz 6,0x7c(31); li 7,0; bl _s801A9A64_29; 29:; lis 9,-32701; addi 30,9,29208; addi 29,30,8; 30:; bl _s801A9A64_30; lwz 0,0x0(31); mr 5,3; lwz 4,0x0(30); addi 30,30,4; cmpwi 0,0; beq 31f; lwz 3,0x1c(31); cmpwi 3,0; beq 31f; lwz 6,0x7c(31); li 7,0; bl _s801A9A64_31; 31:; cmpw 30,29; ble 30b; 32:; lwz 0,0x30c(1); mtspr 8,0; lmw 19,0x2d4(1); addi 1,1,776"
extern "C" void _s801A9A64_0();
extern "C" void _s801A9A64_1();
extern "C" void _s801A9A64_2();
extern "C" void _s801A9A64_3();
extern "C" void _s801A9A64_4();
extern "C" void _s801A9A64_5();
extern "C" void _s801A9A64_6();
extern "C" void _s801A9A64_7();
extern "C" void _s801A9A64_8();
extern "C" void _s801A9A64_9();
extern "C" void _s801A9A64_10();
extern "C" void _s801A9A64_11();
extern "C" void _s801A9A64_12();
extern "C" void _s801A9A64_13();
extern "C" void _s801A9A64_14();
extern "C" void _s801A9A64_15();
extern "C" void _s801A9A64_16();
extern "C" void _s801A9A64_17();
extern "C" void _s801A9A64_18();
extern "C" void _s801A9A64_19();
extern "C" void _s801A9A64_20();
extern "C" void _s801A9A64_21();
extern "C" void _s801A9A64_22();
extern "C" void _s801A9A64_23();
extern "C" void _s801A9A64_24();
extern "C" void _s801A9A64_25();
extern "C" void _s801A9A64_26();
extern "C" void _s801A9A64_27();
extern "C" void _s801A9A64_28();
extern "C" void _s801A9A64_29();
extern "C" void _s801A9A64_30();
extern "C" void _s801A9A64_31();
extern "C" void f_801A9A64() {}
