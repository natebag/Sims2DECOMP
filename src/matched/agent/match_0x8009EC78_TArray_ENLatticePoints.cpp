// 0x8009EC78 TArray<ENLatticePoints, (480 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 3,1; ble 0f; bl _s8009EC78_0; li 4,16; li 5,0; bl _s8009EC78_1; mr 28,3; mr 3,31; bl _s8009EC78_2; mr 29,3; mr 3,31; bl _s8009EC78_3; mr 30,3; mr 3,31; bl _s8009EC78_4; mr 6,3; mr 5,30; mr 4,29; mr 3,28; bl _s8009EC78_5; mr 30,3; mr 3,31; bl _s8009EC78_6; stw 30,0x0(31); 0:; mr 3,31; bl _s8009EC78_7; add 3,3,27; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s8009EC78_8; mr. 3,3; bne 1f; lis 3,-32706; addi 3,3,-28624; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 29,4; mr 31,3; stb 5,0x8(1); cmpwi 29,-1; bne 2f; bl _s8009EC78_9; 2:; mr 3,31; bl _s8009EC78_10; cmplwi 3,1; bgt 3f; mr 3,31; addi 30,29,1; bl _s8009EC78_11; cmplw 30,3; ble 6f; 3:; bl _s8009EC78_12; li 4,16; li 5,0; bl _s8009EC78_13; mr 28,3; mr 3,31; bl _s8009EC78_14; mr 30,3; mr 3,31; bl _s8009EC78_15; cmplw 29,3; ble 4f; mr 3,31; bl _s8009EC78_16; b 5f; 4:; mr 3,29; 5:; mr 5,3; mr 4,30; mr 6,29; mr 3,28; bl _s8009EC78_17; mr 30,3; mr 3,31; bl _s8009EC78_18; stw 30,0x0(31); 6:; lwz 9,0x0(31); lwz 0,0x4(9); cmplw 0,29; bge 8f; 7:; mr 3,31; bl _s8009EC78_19; lwz 9,0x0(31); lbz 11,0x8(1); lwz 0,0x0(9); stbx 11,3,0; lwz 10,0x0(31); lwz 9,0x4(10); addi 9,9,1; stw 9,0x4(10); lwz 11,0x0(31); lwz 0,0x4(11); cmplw 0,29; blt 7b; 8:; lwz 9,0x0(31); mr 3,31; stw 29,0x4(9); bl _s8009EC78_20; mr 29,3; lwz 30,0x0(31); bl _s8009EC78_21; lwz 9,0x0(30); stbx 3,9,29; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8009EC78_0();
extern "C" void _s8009EC78_1();
extern "C" void _s8009EC78_2();
extern "C" void _s8009EC78_3();
extern "C" void _s8009EC78_4();
extern "C" void _s8009EC78_5();
extern "C" void _s8009EC78_6();
extern "C" void _s8009EC78_7();
extern "C" void _s8009EC78_8();
extern "C" void _s8009EC78_9();
extern "C" void _s8009EC78_10();
extern "C" void _s8009EC78_11();
extern "C" void _s8009EC78_12();
extern "C" void _s8009EC78_13();
extern "C" void _s8009EC78_14();
extern "C" void _s8009EC78_15();
extern "C" void _s8009EC78_16();
extern "C" void _s8009EC78_17();
extern "C" void _s8009EC78_18();
extern "C" void _s8009EC78_19();
extern "C" void _s8009EC78_20();
extern "C" void _s8009EC78_21();
extern "C" void f_8009EC78() {}
