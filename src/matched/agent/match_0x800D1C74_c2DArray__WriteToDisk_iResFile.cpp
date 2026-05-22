// 0x800D1C74 _c2DArray::WriteToDisk(iResFile (516 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-160(1); mfspr 0,8; stmw 25,0x84(1); stw 0,0xa4(1); mr 28,3; mr 27,4; lwz 11,0x4(28); mr 25,5; lwz 9,0x8(28); mr 26,6; lwz 0,0x14(28); mr 29,7; mullw 9,9,11; mullw 9,9,0; addi 30,9,64; bl _s800D1C74_0; li 4,12; li 5,0; bl _s800D1C74_1; mr 31,3; cmpwi 30,0; stw 30,0x0(31); beq 0f; bl _s800D1C74_2; mr 4,30; li 5,0; bl _s800D1C74_3; stw 3,0x4(31); b 1f; 0:; stw 30,0x4(31); 1:; li 0,1; cmpwi 31,0; stw 0,0x8(31); bne 2f; li 3,-200; b 10f; 2:; lwz 4,0x4(31); mr 5,30; li 6,1; li 7,0; addi 3,1,8; bl _s800D1C74_4; mr 5,29; mr 3,28; addi 4,1,8; bl _s800D1C74_5; lwz 30,0x10(1); cmpwi 30,0; beq 3f; bl _s800D1C74_6; mr 4,30; li 5,0; bl _s800D1C74_7; mr 29,3; b 4f; 3:; li 29,0; 4:; lwz 5,0x0(31); cmplw 5,30; ble 5f; mr 5,30; 5:; lwz 4,0x4(31); mr 3,29; bl _s800D1C74_8; lwz 0,0x8(31); cmpwi 0,0; beq 6f; bl _s800D1C74_9; lwz 4,0x4(31); bl _s800D1C74_10; 6:; addi 3,1,56; li 0,1; stw 30,0x0(31); addi 4,1,64; stw 29,0x4(31); li 5,64; stw 0,0x8(31); mr 30,3; bl _s800D1C74_11; addi 3,28,16; bl _s800D1C74_12; mr 4,3; mr 3,30; bl _s800D1C74_13; lwz 9,0xc(27); mr 7,30; li 8,0; mr 5,25; lha 3,0xf8(9); mr 6,26; lwz 0,0xfc(9); mr 4,31; add 3,27,3; mtspr 8,0; blrl; mr 3,27; bl _s800D1C74_14; mr. 30,3; beq 8f; cmpwi 31,0; beq 9f; lwz 0,0x8(31); cmpwi 0,0; beq 7f; bl _s800D1C74_15; lwz 4,0x4(31); bl _s800D1C74_16; 7:; bl _s800D1C74_17; mr 4,31; bl _s800D1C74_18; b 9f; 8:; lwz 9,0xc(27); mr 4,31; lha 3,0x108(9); lwz 0,0x10c(9); add 3,27,3; mtspr 8,0; blrl; mr 3,27; bl _s800D1C74_19; mr 30,3; 9:; addi 3,1,8; li 4,2; bl _s800D1C74_20; mr 3,30; 10:; lwz 0,0xa4(1); mtspr 8,0; lmw 25,0x84(1); addi 1,1,160"
extern "C" void _s800D1C74_0();
extern "C" void _s800D1C74_1();
extern "C" void _s800D1C74_2();
extern "C" void _s800D1C74_3();
extern "C" void _s800D1C74_4();
extern "C" void _s800D1C74_5();
extern "C" void _s800D1C74_6();
extern "C" void _s800D1C74_7();
extern "C" void _s800D1C74_8();
extern "C" void _s800D1C74_9();
extern "C" void _s800D1C74_10();
extern "C" void _s800D1C74_11();
extern "C" void _s800D1C74_12();
extern "C" void _s800D1C74_13();
extern "C" void _s800D1C74_14();
extern "C" void _s800D1C74_15();
extern "C" void _s800D1C74_16();
extern "C" void _s800D1C74_17();
extern "C" void _s800D1C74_18();
extern "C" void _s800D1C74_19();
extern "C" void _s800D1C74_20();
extern "C" void f_800D1C74() {}
