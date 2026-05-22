// 0x80191A00 CASTarget::~CASTarget(void) (660 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); lis 9,-32698; lis 11,-32698; mr 30,3; addi 9,9,28680; addi 11,11,28776; stw 9,0x88(30); stw 11,0x80(30); mr 24,4; 0:; mr 3,30; bl _s80191A00_0; cmpwi 3,0; beq 0b; lwz 0,0x0(30); cmpwi 0,0; beq 10f; lwz 3,0x4(30); addi 4,30,40; bl _s80191A00_1; lwz 3,0x8(30); addi 4,30,56; bl _s80191A00_2; lwz 3,0xc(30); addi 4,30,72; bl _s80191A00_3; addi 9,30,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 1f; lwz 0,0x58(30); cmpwi 0,0; beq 2f; 1:; li 11,1; 2:; cmpwi 11,0; beq 3f; lwz 3,0x10(30); bl _s80191A00_4; 3:; addi 9,30,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 4f; lwz 0,0x68(30); cmpwi 0,0; beq 5f; 4:; li 11,1; 5:; cmpwi 11,0; beq 6f; lwz 3,0x14(30); bl _s80191A00_5; 6:; lwz 3,0x18(30); cmpwi 3,0; beq 7f; lwz 4,0x7c(30); bl _s80191A00_6; 7:; lwz 3,0x1c(30); cmpwi 3,0; beq 8f; lwz 4,0x7c(30); bl _s80191A00_7; 8:; lwz 3,0x20(30); cmpwi 3,0; beq 9f; lwz 4,0x7c(30); bl _s80191A00_8; 9:; lwz 3,0x24(30); cmpwi 3,0; beq 10f; lwz 4,0x7c(30); bl _s80191A00_9; 10:; li 0,0; stw 0,-26064(13); bl _s80191A00_10; bl _s80191A00_11; bl _s80191A00_12; bl _s80191A00_13; bl _s80191A00_14; bl _s80191A00_15; bl _s80191A00_16; bl _s80191A00_17; bl _s80191A00_18; bl _s80191A00_19; bl _s80191A00_20; bl _s80191A00_21; bl _s80191A00_22; bl _s80191A00_23; bl _s80191A00_24; bl _s80191A00_25; bl _s80191A00_26; bl _s80191A00_27; bl _s80191A00_28; bl _s80191A00_29; bl _s80191A00_30; bl _s80191A00_31; bl _s80191A00_32; bl _s80191A00_33; bl _s80191A00_34; bl _s80191A00_35; bl _s80191A00_36; addi 3,30,5020; li 4,2; addi 28,30,264; bl _s80191A00_37; addi 27,30,216; addic. 0,30,2632; addi 3,30,4936; addi 26,30,168; addi 25,30,132; mr 29,0; beq 12f; mr 31,3; cmpw 29,31; beq 12f; 11:; addi 31,31,-576; li 4,0; lwz 9,0x4(31); lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; cmpw 29,31; bne 11b; 12:; cmpwi 28,0; beq 14f; mr 31,29; cmpw 28,31; beq 14f; 13:; addi 31,31,-592; li 4,0; lwz 9,0x4(31); lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; cmpw 28,31; bne 13b; 14:; mr 3,27; li 4,2; bl _s80191A00_38; mr 3,26; li 4,2; bl _s80191A00_39; lis 9,-32698; lis 11,-32698; addi 9,9,24424; addi 11,11,-12328; stw 9,0x4(25); andi. 0,24,1; stw 11,0x80(30); beq 15f; mr 3,30; bl _s80191A00_40; 15:; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void _s80191A00_0();
extern "C" void _s80191A00_1();
extern "C" void _s80191A00_2();
extern "C" void _s80191A00_3();
extern "C" void _s80191A00_4();
extern "C" void _s80191A00_5();
extern "C" void _s80191A00_6();
extern "C" void _s80191A00_7();
extern "C" void _s80191A00_8();
extern "C" void _s80191A00_9();
extern "C" void _s80191A00_10();
extern "C" void _s80191A00_11();
extern "C" void _s80191A00_12();
extern "C" void _s80191A00_13();
extern "C" void _s80191A00_14();
extern "C" void _s80191A00_15();
extern "C" void _s80191A00_16();
extern "C" void _s80191A00_17();
extern "C" void _s80191A00_18();
extern "C" void _s80191A00_19();
extern "C" void _s80191A00_20();
extern "C" void _s80191A00_21();
extern "C" void _s80191A00_22();
extern "C" void _s80191A00_23();
extern "C" void _s80191A00_24();
extern "C" void _s80191A00_25();
extern "C" void _s80191A00_26();
extern "C" void _s80191A00_27();
extern "C" void _s80191A00_28();
extern "C" void _s80191A00_29();
extern "C" void _s80191A00_30();
extern "C" void _s80191A00_31();
extern "C" void _s80191A00_32();
extern "C" void _s80191A00_33();
extern "C" void _s80191A00_34();
extern "C" void _s80191A00_35();
extern "C" void _s80191A00_36();
extern "C" void _s80191A00_37();
extern "C" void _s80191A00_38();
extern "C" void _s80191A00_39();
extern "C" void _s80191A00_40();
extern "C" void f_80191A00() {}
