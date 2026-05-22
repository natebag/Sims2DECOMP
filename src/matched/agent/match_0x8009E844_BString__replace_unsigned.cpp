// 0x8009E844 BString::replace(unsigned (772 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 24,0x10(1); stw 0,0x34(1); mr 31,3; mr 27,4; mr 30,5; stb 6,0x8(1); mr 26,7; bl _s8009E844_0; cmplw 27,3; ble 0f; bl _s8009E844_1; 0:; mr 3,31; bl _s8009E844_2; subf 3,27,3; cmplw 30,3; ble 1f; mr 3,31; bl _s8009E844_3; subf 28,27,3; b 2f; 1:; mr 28,30; 2:; mr 3,31; bl _s8009E844_4; subf 3,28,3; not 0,26; cmplw 3,0; blt 3f; bl _s8009E844_5; 3:; cmpwi 26,0; bne 4f; mr 3,31; mr 4,27; mr 5,30; bl _s8009E844_6; b 17f; 4:; mr 3,31; bl _s8009E844_7; cmplwi 3,1; bgt 5f; mr 3,31; bl _s8009E844_8; mr 30,3; mr 3,31; bl _s8009E844_9; subf 3,28,3; add 3,3,26; addi 3,3,1; cmplw 30,3; bge 10f; 5:; bl _s8009E844_10; li 4,16; li 5,0; bl _s8009E844_11; mr 29,3; mr 3,31; bl _s8009E844_12; mr 30,3; mr 3,31; bl _s8009E844_13; mr 6,3; cmplw 28,26; ble 6f; subf 0,26,28; add 6,6,0; 6:; mr 3,29; mr 4,30; mr 5,27; bl _s8009E844_14; mr 25,3; cmplw 26,28; bge 7f; mr 3,31; subf 24,28,26; bl _s8009E844_15; mr 30,3; mr 3,31; bl _s8009E844_16; lwz 0,0x0(25); subf 5,27,3; add 30,30,27; subf 5,28,5; add 0,0,27; add 4,30,28; add 3,0,26; bl _s8009E844_17; b 9f; 7:; mr 3,31; subf 24,28,26; bl _s8009E844_18; subf 3,28,3; subf. 29,27,3; beq 9f; 8:; mr 3,31; bl _s8009E844_19; lwz 9,0x0(25); add 3,3,27; add 3,3,28; add 3,3,29; add 9,9,27; lbz 0,-1(3); add 9,9,26; add 9,9,29; stb 0,-1(9); addic. 29,29,-1; bne 8b; 9:; mr 3,31; bl _s8009E844_20; lwz 30,0x0(25); add 30,30,26; add 30,30,3; subf 30,28,30; bl _s8009E844_21; stb 3,0x0(30); mr 3,31; bl _s8009E844_22; stw 3,0x4(25); mr 3,31; bl _s8009E844_23; stw 25,0x0(31); b 14f; 10:; cmplw 26,28; bge 11f; mr 3,31; subf 24,28,26; bl _s8009E844_24; mr 30,3; mr 3,31; bl _s8009E844_25; mr 29,3; mr 3,31; bl _s8009E844_26; subf 5,27,3; add 30,30,27; add 29,29,27; add 3,30,26; add 4,29,28; subf 5,28,5; bl _s8009E844_27; b 13f; 11:; mr 3,31; subf 24,28,26; bl _s8009E844_28; subf 3,28,3; subf. 29,27,3; beq 13f; 12:; mr 3,31; bl _s8009E844_29; mr 30,3; mr 3,31; bl _s8009E844_30; add 3,3,27; add 30,30,27; add 3,3,28; add 30,30,26; add 3,3,29; add 30,30,29; lbz 0,-1(3); addic. 29,29,-1; stb 0,-1(30); bne 12b; 13:; mr 3,31; bl _s8009E844_31; mr 30,3; mr 3,31; bl _s8009E844_32; add 30,30,26; add 30,30,3; subf 30,28,30; bl _s8009E844_33; stb 3,0x0(30); 14:; li 29,0; cmplw 29,26; bge 16f; 15:; mr 3,31; bl _s8009E844_34; lbz 0,0x8(1); add 3,3,27; stbx 0,3,29; addi 29,29,1; cmplw 29,26; blt 15b; 16:; lwz 9,0x0(31); mr 3,31; lwz 0,0x4(9); add 0,0,24; stw 0,0x4(9); 17:; lwz 0,0x34(1); mtspr 8,0; lmw 24,0x10(1); addi 1,1,48"
extern "C" void _s8009E844_0();
extern "C" void _s8009E844_1();
extern "C" void _s8009E844_2();
extern "C" void _s8009E844_3();
extern "C" void _s8009E844_4();
extern "C" void _s8009E844_5();
extern "C" void _s8009E844_6();
extern "C" void _s8009E844_7();
extern "C" void _s8009E844_8();
extern "C" void _s8009E844_9();
extern "C" void _s8009E844_10();
extern "C" void _s8009E844_11();
extern "C" void _s8009E844_12();
extern "C" void _s8009E844_13();
extern "C" void _s8009E844_14();
extern "C" void _s8009E844_15();
extern "C" void _s8009E844_16();
extern "C" void _s8009E844_17();
extern "C" void _s8009E844_18();
extern "C" void _s8009E844_19();
extern "C" void _s8009E844_20();
extern "C" void _s8009E844_21();
extern "C" void _s8009E844_22();
extern "C" void _s8009E844_23();
extern "C" void _s8009E844_24();
extern "C" void _s8009E844_25();
extern "C" void _s8009E844_26();
extern "C" void _s8009E844_27();
extern "C" void _s8009E844_28();
extern "C" void _s8009E844_29();
extern "C" void _s8009E844_30();
extern "C" void _s8009E844_31();
extern "C" void _s8009E844_32();
extern "C" void _s8009E844_33();
extern "C" void _s8009E844_34();
extern "C" void f_8009E844() {}
