// 0x801DC1B4 R2LTarget::SetupPageShaders(void) (1524 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 22,0x10(1); stw 0,0x3c(1); mr 31,3; li 30,0; addi 3,1,8; li 26,6; bl _s801DC1B4_0; lis 9,-32705; lis 11,-32700; addi 25,9,31292; addi 27,11,-25868; lis 9,-32705; lis 11,-32700; addi 28,9,31412; addi 29,11,-25844; 0:; lwz 0,0x0(31); lwzx 4,30,25; cmpwi 0,0; beq 1f; lwz 3,0x1c(31); cmpwi 3,0; beq 1f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801DC1B4_1; 1:; lwz 0,0x0(31); lwzx 4,30,27; cmpwi 0,0; beq 2f; lwz 3,0x1c(31); cmpwi 3,0; beq 2f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801DC1B4_2; 2:; lwz 0,0x0(31); lwzx 4,30,28; cmpwi 0,0; beq 3f; lwz 3,0x1c(31); cmpwi 3,0; beq 3f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801DC1B4_3; 3:; lwz 0,0x0(31); lwzx 4,30,29; cmpwi 0,0; beq 4f; lwz 3,0x1c(31); cmpwi 3,0; beq 4f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801DC1B4_4; 4:; addi 30,30,4; addic. 26,26,-1; bne 0b; lwz 0,0x9c(31); cmpwi 0,0; bne 5f; addi 3,1,8; li 4,2; bl _s801DC1B4_5; b 28f; 5:; mr 3,31; li 4,0; bl _s801DC1B4_6; li 26,0; lwz 0,0x9c(31); mr 28,3; cmpw 28,0; bge 16f; lis 9,-32697; mulli 27,28,28; addi 22,9,23428; lis 10,-32705; lis 11,-32700; lis 9,-32705; addi 24,11,-25868; addi 23,9,31700; addi 25,10,31292; 6:; lwz 30,0x98(31); add 29,30,27; lwz 3,0x8(29); cmpwi 3,0; beq 7f; lhz 0,0xc(3); bl _s801DC1B4_7; li 0,0; stw 0,0x8(29); 7:; lwzx 4,30,27; lis 3,-32697; addi 3,3,24012; bl _s801DC1B4_8; mr. 3,3; beq 8f; lwz 0,0x0(31); lwz 5,0x4(3); cmpwi 0,0; lwz 4,0x0(25); beq 10f; lwz 3,0x1c(31); cmpwi 3,0; beq 10f; lwz 6,0x7c(31); li 7,0; bl _s801DC1B4_9; b 10f; 8:; lwz 9,0x4(29); addi 4,29,8; lwz 3,0xc(9); bl _s801DC1B4_10; lwz 5,0x8(29); cmpwi 5,0; beq 9f; lwz 0,0x0(31); lhz 9,0xc(5); cmpwi 0,0; lwz 4,0x0(25); beq 10f; lwz 3,0x1c(31); cmpwi 3,0; beq 10f; lwz 6,0x7c(31); li 7,0; bl _s801DC1B4_11; b 10f; 9:; lwz 0,0x0(31); lwz 4,0x0(25); cmpwi 0,0; beq 10f; lwz 3,0x1c(31); cmpwi 3,0; beq 10f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801DC1B4_12; 10:; lwz 3,0x94(31); li 30,-1; rlwinm 3,3,4,0,27; addi 3,3,244; add 3,3,22; bl _s801DC1B4_13; mr. 3,3; beq 11f; lwz 4,0x4(29); cmpwi 4,0; beq 11f; bl _s801DC1B4_14; mr 30,3; 11:; lwz 0,0x18(29); cmpwi 0,0; beq 12f; lwz 0,0x0(31); lwz 4,0x0(24); cmpwi 0,0; beq 15f; lwz 3,0x1c(31); cmpwi 3,0; beq 15f; lis 5,-10185; lwz 6,0x7c(31); ori 5,5,28884; b 13f; 12:; cmpwi 30,-1; bne 14f; lwz 0,0x0(31); lwz 4,0x0(24); cmpwi 0,0; beq 15f; lwz 3,0x1c(31); cmpwi 3,0; beq 15f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; 13:; li 7,0; bl _s801DC1B4_15; b 15f; 14:; lwz 9,0x0(31); rlwinm 0,30,2,0,29; lwzx 5,23,0; cmpwi 9,0; lwz 4,0x0(24); beq 15f; lwz 3,0x1c(31); cmpwi 3,0; beq 15f; lwz 6,0x7c(31); li 7,0; bl _s801DC1B4_16; 15:; addi 26,26,1; addi 24,24,4; addi 25,25,4; addi 27,27,28; addi 28,28,1; cmpwi 26,5; bgt 16f; lwz 0,0x9c(31); cmpw 28,0; blt 6b; 16:; mr 3,31; li 4,0; bl _s801DC1B4_17; mr. 3,3; blt 25f; lwz 0,0x9c(31); mr 28,3; li 26,0; cmpw 28,0; bge 25f; lis 9,-32697; mulli 27,28,28; addi 22,9,23428; lis 10,-32705; lis 11,-32700; lis 9,-32705; addi 24,11,-25844; addi 23,9,31700; addi 25,10,31412; 17:; lwz 30,0x98(31); add 29,30,27; lwz 3,0x8(29); cmpwi 3,0; beq 18f; lhz 0,0xc(3); bl _s801DC1B4_18; li 0,0; stw 0,0x8(29); 18:; lwzx 4,30,27; lis 3,-32697; addi 3,3,24012; bl _s801DC1B4_19; mr. 3,3; beq 19f; lwz 0,0x0(31); lwz 5,0x4(3); cmpwi 0,0; lwz 4,0x0(25); beq 21f; lwz 3,0x1c(31); cmpwi 3,0; beq 21f; lwz 6,0x7c(31); li 7,0; bl _s801DC1B4_20; b 21f; 19:; lwz 9,0x4(29); addi 4,29,8; lwz 3,0xc(9); bl _s801DC1B4_21; lwz 5,0x8(29); cmpwi 5,0; beq 20f; lwz 0,0x0(31); lhz 9,0xc(5); cmpwi 0,0; lwz 4,0x0(25); beq 21f; lwz 3,0x1c(31); cmpwi 3,0; beq 21f; lwz 6,0x7c(31); li 7,0; bl _s801DC1B4_22; b 21f; 20:; lwz 0,0x0(31); lwz 4,0x0(25); cmpwi 0,0; beq 21f; lwz 3,0x1c(31); cmpwi 3,0; beq 21f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801DC1B4_23; 21:; lwz 3,0x94(31); li 30,-1; rlwinm 3,3,4,0,27; addi 3,3,244; add 3,3,22; bl _s801DC1B4_24; mr. 3,3; beq 22f; lwz 4,0x4(29); cmpwi 4,0; beq 22f; bl _s801DC1B4_25; mr 30,3; 22:; cmpwi 30,-1; bne 23f; lwz 0,0x0(31); lwz 4,0x0(24); cmpwi 0,0; beq 24f; lwz 3,0x1c(31); cmpwi 3,0; beq 24f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801DC1B4_26; b 24f; 23:; lwz 9,0x0(31); rlwinm 0,30,2,0,29; lwzx 5,23,0; cmpwi 9,0; lwz 4,0x0(24); beq 24f; lwz 3,0x1c(31); cmpwi 3,0; beq 24f; lwz 6,0x7c(31); li 7,0; bl _s801DC1B4_27; 24:; addi 26,26,1; addi 24,24,4; addi 25,25,4; addi 27,27,28; addi 28,28,1; cmpwi 26,5; bgt 25f; lwz 0,0x9c(31); cmpw 28,0; blt 17b; 25:; lwz 0,-29696(13); cmpwi 0,0; bne 27f; addi 3,31,468; li 30,0; mr 29,3; li 26,6; bl _s801DC1B4_28; mr 31,29; lis 9,-32705; lis 11,-32705; addi 27,9,31532; addi 28,11,31676; 26:; lwzx 4,30,27; li 5,0; mr 3,31; bl _s801DC1B4_29; mr 3,31; li 4,12; bl _s801DC1B4_30; lwzx 4,30,28; mr 3,31; li 5,0; addi 30,30,4; bl _s801DC1B4_31; mr 3,31; li 4,12; bl _s801DC1B4_32; addic. 26,26,-1; bne 26b; mr 3,29; bl _s801DC1B4_33; 27:; addi 3,1,8; li 4,2; bl _s801DC1B4_34; 28:; lwz 0,0x3c(1); mtspr 8,0; lmw 22,0x10(1); addi 1,1,56"

extern "C" void _s801DC1B4_0();
extern "C" void _s801DC1B4_1();
extern "C" void _s801DC1B4_2();
extern "C" void _s801DC1B4_3();
extern "C" void _s801DC1B4_4();
extern "C" void _s801DC1B4_5();
extern "C" void _s801DC1B4_6();
extern "C" void _s801DC1B4_7();
extern "C" void _s801DC1B4_8();
extern "C" void _s801DC1B4_9();
extern "C" void _s801DC1B4_10();
extern "C" void _s801DC1B4_11();
extern "C" void _s801DC1B4_12();
extern "C" void _s801DC1B4_13();
extern "C" void _s801DC1B4_14();
extern "C" void _s801DC1B4_15();
extern "C" void _s801DC1B4_16();
extern "C" void _s801DC1B4_17();
extern "C" void _s801DC1B4_18();
extern "C" void _s801DC1B4_19();
extern "C" void _s801DC1B4_20();
extern "C" void _s801DC1B4_21();
extern "C" void _s801DC1B4_22();
extern "C" void _s801DC1B4_23();
extern "C" void _s801DC1B4_24();
extern "C" void _s801DC1B4_25();
extern "C" void _s801DC1B4_26();
extern "C" void _s801DC1B4_27();
extern "C" void _s801DC1B4_28();
extern "C" void _s801DC1B4_29();
extern "C" void _s801DC1B4_30();
extern "C" void _s801DC1B4_31();
extern "C" void _s801DC1B4_32();
extern "C" void _s801DC1B4_33();
extern "C" void _s801DC1B4_34();

struct R2LTarget {
    void SetupPageShaders();
};

void R2LTarget::SetupPageShaders() {
}
