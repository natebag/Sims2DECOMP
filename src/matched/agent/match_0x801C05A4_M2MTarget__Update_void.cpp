// 0x801C05A4 M2MTarget::Update(void) (1020 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; lwz 0,0x168(31); cmpwi 0,5; beq 30f; lis 11,-32697; li 10,0; lwz 9,0x5f08(11); lwz 0,0x134(9); cmpwi 0,0; beq 0f; cmpwi 0,3; beq 0f; li 10,1; 0:; cmpwi 10,0; bne 30f; lis 9,-32697; lwz 3,0x5f08(9); cmpwi 3,0; beq 1f; bl _s801C05A4_0; cmpwi 3,0; bne 2f; 1:; lwz 9,0x16c(31); lwz 0,0x168(31); cmpw 9,0; beq 2f; mr 3,31; bl _s801C05A4_1; 2:; lwz 0,0x168(31); cmpwi 0,4; bne 3f; lis 9,-32697; li 4,48; lwz 3,0x5f10(9); bl _s801C05A4_2; cmpwi 3,0; beq 30f; mr 3,31; bl _s801C05A4_3; li 0,5; stw 0,0x168(31); b 30f; 3:; lwz 0,0x180(31); cmpwi 0,0; beq 12f; lwz 9,0x11c(31); li 0,0; stw 0,0x180(31); cmpwi 9,7; beq 10f; bgt 4f; cmpwi 9,0; beq 8f; cmpwi 9,4; beq 11f; b 12f; 4:; cmpwi 9,8; beq 5f; cmpwi 9,13; beq 6f; b 12f; 5:; li 0,6; b 7f; 6:; li 0,14; 7:; mr 3,31; stw 0,0x11c(31); bl _s801C05A4_4; b 12f; 8:; lis 9,-32697; lwz 9,0x5bec(9); cmpwi 9,0; beq 9f; lwz 0,0xa4(9); cmpwi 0,0; beq 9f; cmpwi 0,2; bne 12f; mr 3,31; bl _s801C05A4_5; b 12f; 9:; mr 3,31; bl _s801C05A4_6; b 12f; 10:; mr 3,31; bl _s801C05A4_7; b 12f; 11:; mr 3,31; bl _s801C05A4_8; 12:; lwz 0,0x11c(31); cmpwi 0,10; bne 13f; mr 3,31; bl _s801C05A4_9; 13:; lwz 0,0x11c(31); cmpwi 0,6; bne 14f; lwz 0,0x168(31); cmpwi 0,1; beq 14f; mr 3,31; bl _s801C05A4_10; cmpwi 3,0; beq 14f; addi 3,31,132; bl _s801C05A4_11; lis 9,-32697; li 11,0; addi 9,9,24012; li 10,9; stw 11,0x44c(9); li 0,1; stw 11,0x448(9); stw 10,0x11c(31); stw 0,0x168(31); 14:; lwz 0,0x168(31); cmpwi 0,2; bne 18f; lwz 0,0x184(31); cmpwi 0,0; beq 18f; lwz 0,0x10c(31); cmpwi 0,255; bne 18f; lwz 0,0x11c(31); cmpwi 0,9; beq 15f; cmpwi 0,15; bne 18f; 15:; li 30,0; addi 4,1,8; stw 30,0x8(1); li 3,0; bl _s801C05A4_12; stw 30,0xc(1); li 3,1; addi 4,1,12; bl _s801C05A4_13; lwz 0,0x11c(31); cmpwi 0,9; bne 16f; lwz 0,0x8(1); cmpwi 0,0; bne 16f; lwz 0,0xc(1); cmpwi 0,0; bne 16f; li 0,6; mr 3,31; stw 0,0x11c(31); bl _s801C05A4_14; b 18f; 16:; lwz 9,0x8(1); lwz 0,0x178(31); cmpw 9,0; bne 17f; lwz 9,0xc(1); lwz 0,0x17c(31); cmpw 9,0; beq 18f; 17:; li 0,1; stw 0,0x168(31); 18:; lwz 11,0x118(31); cmpwi 11,0; beq 30f; lwz 9,0x8(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; mr 30,3; cmpwi 30,4; beq 20f; bgt 19f; cmpwi 30,1; beq 21f; blt 30f; b 22f; 19:; cmpwi 30,6; beq 24f; blt 22f; cmpwi 30,7; beq 22f; cmpwi 30,8; beq 25f; b 30f; 20:; lwz 0,0x11c(31); cmpwi 0,15; beq 21f; cmpwi 0,2; bne 23f; 21:; mr 3,31; bl _s801C05A4_15; b 30f; 22:; lwz 0,0x11c(31); cmpwi 0,2; bne 23f; lwz 11,0x118(31); lwz 9,0x8(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x10c(31); addi 9,31,344; rlwinm 0,0,2,0,29; stwx 3,9,0; 23:; mr 3,31; bl _s801C05A4_16; b 30f; 24:; mr 3,31; bl _s801C05A4_17; b 30f; 25:; lwz 11,0x118(31); cmpwi 11,0; beq 26f; lwz 9,0x8(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 26:; lwz 9,0x11c(31); li 0,0; stw 0,0x118(31); cmpwi 9,9; bne 27f; stw 30,0x11c(31); mr 3,31; b 28f; 27:; cmpwi 9,15; bne 29f; li 0,13; mr 3,31; stw 0,0x11c(31); 28:; bl _s801C05A4_18; li 9,255; li 0,1; stw 0,0x180(31); stw 9,0x110(31); stw 9,0x10c(31); b 30f; 29:; mr 3,31; bl _s801C05A4_19; 30:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s801C05A4_0();
extern "C" void _s801C05A4_1();
extern "C" void _s801C05A4_2();
extern "C" void _s801C05A4_3();
extern "C" void _s801C05A4_4();
extern "C" void _s801C05A4_5();
extern "C" void _s801C05A4_6();
extern "C" void _s801C05A4_7();
extern "C" void _s801C05A4_8();
extern "C" void _s801C05A4_9();
extern "C" void _s801C05A4_10();
extern "C" void _s801C05A4_11();
extern "C" void _s801C05A4_12();
extern "C" void _s801C05A4_13();
extern "C" void _s801C05A4_14();
extern "C" void _s801C05A4_15();
extern "C" void _s801C05A4_16();
extern "C" void _s801C05A4_17();
extern "C" void _s801C05A4_18();
extern "C" void _s801C05A4_19();
extern "C" void f_801C05A4() {}
