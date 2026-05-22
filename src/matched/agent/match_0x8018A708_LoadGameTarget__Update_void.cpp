// 0x8018A708 LoadGameTarget::Update(void) (992 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; lwz 0,0x10c(31); cmpwi 0,0; bne 35f; lis 11,-32697; li 10,0; lwz 9,0x5f08(11); lwz 0,0x134(9); cmpwi 0,0; beq 0f; cmpwi 0,3; beq 0f; li 10,1; 0:; cmpwi 10,0; bne 35f; lwz 0,0x12c(31); cmpwi 0,6; beq 4f; bgt 1f; cmpwi 0,-1; beq 2f; b 5f; 1:; cmpwi 0,22; beq 3f; b 5f; 2:; stw 10,0x12c(31); mr 3,31; bl _s8018A708_0; b 5f; 3:; li 0,2; stw 0,0x10c(31); b 35f; 4:; li 0,21; mr 3,31; stw 0,0x12c(31); bl _s8018A708_1; 5:; lwz 0,0x12c(31); cmpwi 0,0; beq 10f; cmpwi 0,24; beq 10f; cmpwi 0,4; beq 10f; cmpwi 0,19; beq 10f; cmpwi 0,23; beq 10f; cmpwi 0,22; beq 10f; cmpwi 0,21; beq 10f; lwz 9,0x124(31); lwz 0,-26460(13); cmpw 9,0; beq 6f; addi 3,31,132; bl _s8018A708_2; lwz 9,-26460(13); li 0,-1; stw 0,0x12c(31); stw 9,0x124(31); b 35f; 6:; lwz 3,0x128(31); li 30,0; stw 30,0x8(1); addi 4,1,8; bl _s8018A708_3; lwz 0,0x8(1); cmpwi 0,0; bne 9f; lwz 0,0x11c(31); cmpwi 0,0; beq 7f; lwz 0,0x128(31); lwz 3,0x118(31); subfic 0,0,1; mr 4,0; stw 0,0x128(31); bl _s8018A708_4; li 0,1; stw 30,0x11c(31); stw 0,0x120(31); b 35f; 7:; lwz 0,0x120(31); cmpwi 0,0; beq 8f; stw 30,0x120(31); addi 3,31,132; bl _s8018A708_5; li 0,8; stw 0,0x10c(31); b 35f; 8:; addi 3,31,132; bl _s8018A708_6; li 0,6; stw 30,0x130(31); stw 0,0x12c(31); b 35f; 9:; stw 30,0x120(31); stw 30,0x11c(31); 10:; lwz 0,0x130(31); cmpwi 0,0; beq 35f; lwz 0,0x12c(31); li 9,0; stw 9,0x130(31); cmpwi 0,14; beq 25f; bgt 13f; cmpwi 0,4; beq 21f; bgt 11f; cmpwi 0,2; beq 19f; bgt 20f; cmpwi 0,1; beq 16f; b 35f; 11:; cmpwi 0,8; beq 35f; bgt 12f; cmpwi 0,5; beq 23f; b 35f; 12:; cmpwi 0,10; beq 24f; b 35f; 13:; cmpwi 0,19; beq 28f; bgt 14f; cmpwi 0,16; beq 27f; blt 26f; cmpwi 0,17; beq 33f; b 35f; 14:; cmpwi 0,23; beq 22f; bgt 15f; cmpwi 0,20; beq 34f; b 35f; 15:; cmpwi 0,24; beq 18f; b 35f; 16:; mr 3,31; bl _s8018A708_7; cmpwi 3,0; beq 35f; lwz 0,0x140(31); cmpwi 0,0; li 0,2; beq 17f; li 0,3; 17:; stw 0,0x12c(31); li 0,1; stw 0,0x130(31); b 35f; 18:; lwz 3,0x128(31); lis 4,171; ori 4,4,52719; bl _s8018A708_8; li 0,1; stw 0,0x130(31); stw 0,0x12c(31); b 35f; 19:; mr 3,31; bl _s8018A708_9; b 35f; 20:; li 0,4; stw 9,0x134(31); stw 0,0x12c(31); mr 3,31; bl _s8018A708_10; b 35f; 21:; mr 3,31; bl _s8018A708_11; b 35f; 22:; mr 3,31; bl _s8018A708_12; b 35f; 23:; mr 3,31; bl _s8018A708_13; b 35f; 24:; li 0,14; mr 3,31; stw 0,0x12c(31); bl _s8018A708_14; b 35f; 25:; li 0,15; mr 3,31; stw 0,0x12c(31); bl _s8018A708_15; b 35f; 26:; li 0,19; mr 3,31; stw 0,0x12c(31); bl _s8018A708_16; b 35f; 27:; mr 3,31; bl _s8018A708_17; b 35f; 28:; lwz 3,0x128(31); addi 30,31,132; li 28,1; bl _s8018A708_18; mr 29,3; mr 3,30; bl _s8018A708_19; lwz 9,-26512(13); cmpwi 29,1; stw 28,0xc(9); bne 29f; lwz 3,0x128(31); addi 4,1,12; bl _s8018A708_20; cmpwi 3,-1; beq 30f; lwz 0,0xc(1); cmpwi 0,0; li 0,20; bne 32f; b 31f; 29:; cmpwi 29,-1; bne 31f; 30:; mr 3,30; bl _s8018A708_21; li 0,6; stw 0,0x12c(31); b 35f; 31:; li 0,17; 32:; stw 28,0x130(31); stw 0,0x12c(31); b 35f; 33:; mr 3,31; bl _s8018A708_22; b 35f; 34:; mr 3,31; bl _s8018A708_23; 35:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8018A708_0();
extern "C" void _s8018A708_1();
extern "C" void _s8018A708_2();
extern "C" void _s8018A708_3();
extern "C" void _s8018A708_4();
extern "C" void _s8018A708_5();
extern "C" void _s8018A708_6();
extern "C" void _s8018A708_7();
extern "C" void _s8018A708_8();
extern "C" void _s8018A708_9();
extern "C" void _s8018A708_10();
extern "C" void _s8018A708_11();
extern "C" void _s8018A708_12();
extern "C" void _s8018A708_13();
extern "C" void _s8018A708_14();
extern "C" void _s8018A708_15();
extern "C" void _s8018A708_16();
extern "C" void _s8018A708_17();
extern "C" void _s8018A708_18();
extern "C" void _s8018A708_19();
extern "C" void _s8018A708_20();
extern "C" void _s8018A708_21();
extern "C" void _s8018A708_22();
extern "C" void _s8018A708_23();
extern "C" void f_8018A708() {}
