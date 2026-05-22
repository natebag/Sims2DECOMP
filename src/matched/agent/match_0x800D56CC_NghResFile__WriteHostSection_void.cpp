// 0x800D56CC NghResFile::WriteHostSection(void (884 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-128(1); mfspr 0,8; stmw 14,0x38(1); stw 0,0x84(1); stw 4,0x2c(1); mr 25,3; lis 4,21569; addi 30,1,16; ori 4,4,21588; bl _s800D56CC_0; mr 28,30; lwz 3,0x0(3); mr 4,30; addi 16,1,20; addi 14,1,24; bl _s800D56CC_1; addi 0,1,28; addi 3,3,3; stw 0,0x34(1); rlwinm 29,3,0,0,29; lwz 26,0x10(1); li 30,0; lwz 9,0x24(25); addi 18,1,32; addi 17,1,36; addi 15,1,40; addi 9,9,1; stw 9,0x30(1); 0:; addi 30,30,1; mr 3,25; mr 4,30; bl _s800D56CC_2; lis 4,21321; mr 3,25; ori 4,4,19785; bl _s800D56CC_3; lwz 3,0x0(3); mr 4,28; bl _s800D56CC_4; lwz 0,0x10(1); add 29,29,3; addi 9,29,3; lis 4,18511; add 26,26,0; rlwinm 29,9,0,0,29; ori 4,4,21843; mr 3,25; bl _s800D56CC_5; lwz 3,0x0(3); mr 4,28; bl _s800D56CC_6; add 29,29,3; lwz 0,0x10(1); addi 9,29,3; cmpwi 30,15; add 26,26,0; rlwinm 29,9,0,0,29; ble 0b; mulli 30,26,14; lwz 21,0x34(1); mr 19,16; mr 20,14; mr 22,18; mr 23,17; mr 24,15; addi 0,30,3; rlwinm 30,0,0,0,29; bl _s800D56CC_7; addi 27,30,28; add 4,29,27; li 5,64; li 6,0; li 7,0; bl _s800D56CC_8; mr 31,3; add 11,29,30; rlwinm 0,26,2,0,29; li 10,0; li 8,28; addi 28,31,28; li 9,8; stw 10,0x10(31); stw 9,0x14(31); add 29,28,0; stw 10,0x0(31); add 30,29,0; stw 11,0x8(31); add 0,30,0; stw 8,0x4(31); lis 5,21569; stw 26,0x18(31); mr 3,25; stw 8,0x28(1); mr 4,31; lwz 8,0x34(1); ori 5,5,21588; stw 30,0x1c(1); mr 6,16; mr 7,14; stw 27,0x24(1); mr 9,18; stw 0,0x20(1); mr 10,17; stw 28,0x14(1); stw 29,0x18(1); stw 15,0x8(1); bl _s800D56CC_9; li 30,0; 1:; addi 30,30,1; mr 3,25; mr 4,30; bl _s800D56CC_10; lis 5,21321; stw 24,0x8(1); mr 3,25; mr 4,31; ori 5,5,19785; mr 6,19; mr 7,20; mr 8,21; mr 9,22; mr 10,23; bl _s800D56CC_11; lis 5,18511; stw 24,0x8(1); mr 3,25; mr 4,31; ori 5,5,21843; mr 6,19; mr 7,20; mr 8,21; mr 9,22; mr 10,23; bl _s800D56CC_12; cmpwi 30,15; ble 1b; lwz 4,0x30(1); mr 3,25; bl _s800D56CC_13; lis 9,-32696; addi 27,9,25388; lwz 11,0x4(27); lwz 28,0x3c(11); bl _s800D56CC_14; li 6,0; li 7,0; mr 4,28; li 5,64; bl _s800D56CC_15; mr 30,3; li 4,0; mr 5,28; bl _s800D56CC_16; lwz 3,0x4(31); lwz 4,0x8(31); add 29,30,3; subf 6,3,28; add 3,31,3; mr 5,29; bl _s800D56CC_17; mr. 0,3; bgt 2f; bl _s800D56CC_18; mr 4,31; bl _s800D56CC_19; bl _s800D56CC_20; mr 4,30; bl _s800D56CC_21; li 3,-4; b 5f; 2:; lwz 3,0x4(31); mr 4,31; stw 0,0xc(31); mr 5,3; subf 3,3,29; crxor 6,6,6; bl _s800D56CC_22; bl _s800D56CC_23; mr 4,31; bl _s800D56CC_24; li 0,0; lwz 9,0xc(30); lwz 4,0x4(30); mr 3,30; stw 0,0x10(30); add 4,9,4; bl _s800D56CC_25; stw 3,0x10(30); lwz 0,0x2c(1); cmpwi 0,0; bne 3f; mr 3,25; bl _s800D56CC_26; lwz 9,0x4(27); mr 4,27; lwz 0,0xc(30); mr 5,30; lwz 7,0x4(30); lwz 6,0x38(9); add 7,0,7; bl _s800D56CC_27; cmpwi 3,0; beq 4f; bl _s800D56CC_28; mr 4,30; bl _s800D56CC_29; li 3,0; b 5f; 3:; lwz 3,0x2c(1); mr 5,28; mr 4,30; bl _s800D56CC_30; 4:; bl _s800D56CC_31; mr 4,30; bl _s800D56CC_32; li 3,1; 5:; lwz 0,0x84(1); mtspr 8,0; lmw 14,0x38(1); addi 1,1,128"
extern "C" void _s800D56CC_0();
extern "C" void _s800D56CC_1();
extern "C" void _s800D56CC_2();
extern "C" void _s800D56CC_3();
extern "C" void _s800D56CC_4();
extern "C" void _s800D56CC_5();
extern "C" void _s800D56CC_6();
extern "C" void _s800D56CC_7();
extern "C" void _s800D56CC_8();
extern "C" void _s800D56CC_9();
extern "C" void _s800D56CC_10();
extern "C" void _s800D56CC_11();
extern "C" void _s800D56CC_12();
extern "C" void _s800D56CC_13();
extern "C" void _s800D56CC_14();
extern "C" void _s800D56CC_15();
extern "C" void _s800D56CC_16();
extern "C" void _s800D56CC_17();
extern "C" void _s800D56CC_18();
extern "C" void _s800D56CC_19();
extern "C" void _s800D56CC_20();
extern "C" void _s800D56CC_21();
extern "C" void _s800D56CC_22();
extern "C" void _s800D56CC_23();
extern "C" void _s800D56CC_24();
extern "C" void _s800D56CC_25();
extern "C" void _s800D56CC_26();
extern "C" void _s800D56CC_27();
extern "C" void _s800D56CC_28();
extern "C" void _s800D56CC_29();
extern "C" void _s800D56CC_30();
extern "C" void _s800D56CC_31();
extern "C" void _s800D56CC_32();
extern "C" void f_800D56CC() {}
