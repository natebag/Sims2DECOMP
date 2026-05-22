// 0x8018D9BC SaveGameTarget::Update(void) (1064 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; lwz 0,0x110(31); cmpwi 0,0; bne 35f; lis 11,-32697; li 10,0; lwz 9,0x5f08(11); lwz 0,0x134(9); cmpwi 0,0; beq 0f; cmpwi 0,3; beq 0f; li 10,1; 0:; cmpwi 10,0; bne 35f; lwz 0,0x12c(31); cmpwi 7,0,21; bne cr7,1f; li 0,22; stw 10,0x130(31); stw 0,0x12c(31); mr 3,31; bl _s8018D9BC_0; b 35f; 1:; cmpwi 0,22; beq 6f; cmpwi 0,0; beq 6f; cmpwi 0,18; beq 6f; cmpwi 0,13; beq 6f; beq cr7,6f; cmpwi 0,23; beq 6f; cmpwi 0,20; beq 6f; cmpwi 0,14; beq 6f; cmpwi 0,24; beq 6f; lwz 0,-26748(13); cmpwi 0,0; bne 6f; lwz 3,0x128(31); li 30,1; stw 30,0x8(1); addi 4,1,8; bl _s8018D9BC_1; lwz 0,0x12c(31); mr 29,3; cmpwi 0,19; bne 2f; lwz 0,0x8(1); cmpwi 0,0; bne 2f; stw 30,0x154(31); b 6f; 2:; cmpwi 29,1; bne 5f; lwz 30,0x8(1); cmpwi 30,0; bne 5f; lwz 9,0x11c(31); cmpwi 9,0; beq 3f; lwz 0,0x128(31); lwz 3,0x118(31); subfic 0,0,1; mr 4,0; stw 0,0x128(31); bl _s8018D9BC_2; stw 29,0x120(31); stw 30,0x11c(31); b 35f; 3:; lwz 0,0x120(31); cmpwi 0,0; beq 4f; stw 9,0x120(31); addi 3,31,132; bl _s8018D9BC_3; li 0,8; stw 0,0x110(31); b 35f; 4:; addi 3,31,132; bl _s8018D9BC_4; b 23f; 5:; li 0,0; stw 0,0x120(31); stw 0,0x11c(31); 6:; lwz 0,0x130(31); cmpwi 0,0; beq 35f; lwz 30,0x12c(31); li 0,0; stw 0,0x130(31); cmpwi 30,14; beq 20f; bgt 9f; cmpwi 30,10; beq 16f; bgt 8f; cmpwi 30,1; beq 14f; bgt 7f; cmpwi 30,0; beq 12f; b 35f; 7:; cmpwi 30,9; beq 15f; b 35f; 8:; cmpwi 30,12; beq 19f; bgt 17f; b 25f; 9:; cmpwi 30,19; beq 30f; bgt 10f; cmpwi 30,17; beq 27f; bgt 28f; cmpwi 30,15; beq 18f; b 35f; 10:; cmpwi 30,23; beq 13f; bgt 11f; cmpwi 30,20; beq 26f; b 35f; 11:; cmpwi 30,24; beq 34f; b 35f; 12:; mr 3,31; bl _s8018D9BC_5; b 35f; 13:; li 0,2; stw 0,0x110(31); b 35f; 14:; mr 3,31; bl _s8018D9BC_6; cmpwi 3,0; beq 35f; li 0,18; stw 30,0x130(31); stw 0,0x12c(31); b 35f; 15:; mr 3,31; bl _s8018D9BC_7; b 35f; 16:; mr 3,31; bl _s8018D9BC_8; b 35f; 17:; mr 3,31; bl _s8018D9BC_9; b 35f; 18:; mr 3,31; bl _s8018D9BC_10; b 35f; 19:; mr 3,31; bl _s8018D9BC_11; b 35f; 20:; lwz 3,0x128(31); li 29,1; stw 0,0x150(31); bl _s8018D9BC_12; mr 30,3; stw 29,0x14c(31); addi 3,31,132; bl _s8018D9BC_13; lwz 9,-26512(13); cmpwi 30,1; stw 29,0xc(9); bne 22f; stw 29,0x150(31); addi 4,1,12; lwz 3,0x128(31); bl _s8018D9BC_14; cmpwi 3,-1; li 0,21; beq 21f; lwz 0,0xc(1); cmpwi 0,0; li 0,12; beq 21f; li 0,15; 21:; stw 0,0x12c(31); li 0,1; stw 0,0x130(31); b 35f; 22:; cmpwi 30,-1; bne 24f; 23:; li 0,21; stw 0,0x12c(31); b 35f; 24:; li 0,12; stw 29,0x130(31); stw 0,0x12c(31); b 35f; 25:; mr 3,31; bl _s8018D9BC_15; b 35f; 26:; mr 3,31; bl _s8018D9BC_16; b 35f; 27:; mr 3,31; bl _s8018D9BC_17; b 35f; 28:; lwz 0,0x138(31); andi. 30,0,2; beq 29f; addi 3,31,132; bl _s8018D9BC_18; li 0,1; stw 0,0x110(31); b 35f; 29:; mr 3,31; bl _s8018D9BC_19; stw 30,0x134(31); stw 30,0x154(31); b 35f; 30:; lwz 0,0x134(31); cmpwi 0,5; bgt 31f; cmpwi 0,3; bge 33f; cmpwi 0,0; beq 32f; b 35f; 31:; cmpwi 0,10; bgt 35f; cmpwi 0,7; bge 33f; b 35f; 32:; lwz 11,-26532(13); li 0,1; stw 0,0x130(31); lis 4,-32693; addi 4,4,-11760; addi 30,31,352; lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; stfs f1,0x4(30); mr 3,31; bl _s8018D9BC_20; stw 3,0x140(31); li 0,3; stw 0,0x134(31); 33:; mr 3,31; bl _s8018D9BC_21; b 35f; 34:; mr 3,31; bl _s8018D9BC_22; 35:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8018D9BC_0();
extern "C" void _s8018D9BC_1();
extern "C" void _s8018D9BC_2();
extern "C" void _s8018D9BC_3();
extern "C" void _s8018D9BC_4();
extern "C" void _s8018D9BC_5();
extern "C" void _s8018D9BC_6();
extern "C" void _s8018D9BC_7();
extern "C" void _s8018D9BC_8();
extern "C" void _s8018D9BC_9();
extern "C" void _s8018D9BC_10();
extern "C" void _s8018D9BC_11();
extern "C" void _s8018D9BC_12();
extern "C" void _s8018D9BC_13();
extern "C" void _s8018D9BC_14();
extern "C" void _s8018D9BC_15();
extern "C" void _s8018D9BC_16();
extern "C" void _s8018D9BC_17();
extern "C" void _s8018D9BC_18();
extern "C" void _s8018D9BC_19();
extern "C" void _s8018D9BC_20();
extern "C" void _s8018D9BC_21();
extern "C" void _s8018D9BC_22();
extern "C" void f_8018D9BC() {}
