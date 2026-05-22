// 0x8009CECC BString::replace_str(unsigned (612 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; mfcr 12; stmw 24,0x10(1); stw 0,0x34(1); stw 12,0xc(1); mr 31,3; mr 26,5; mr 28,4; mr 24,6; mr 27,7; bl _s8009CECC_0; cmplw 26,3; ble 0f; bl _s8009CECC_1; 0:; mr 3,31; bl _s8009CECC_2; subf 3,28,3; not 0,27; cmplw 3,0; blt 1f; bl _s8009CECC_3; 1:; mr 3,31; bl _s8009CECC_4; cmplwi 3,1; bgt 2f; mr 3,31; bl _s8009CECC_5; mr 30,3; mr 3,31; bl _s8009CECC_6; add 3,3,27; addi 0,28,-1; subf 3,0,3; cmplw 30,3; bge 3f; 2:; bl _s8009CECC_7; subf 25,28,27; li 4,16; li 5,0; bl _s8009CECC_8; cmpwi 4,27,0; mr 29,3; mr 3,31; bl _s8009CECC_9; mr 30,3; mr 3,31; bl _s8009CECC_10; add 6,3,27; mr 4,30; subf 6,28,6; mr 5,26; mr 3,29; bl _s8009CECC_11; mr 29,3; mr 3,31; bl _s8009CECC_12; mr 30,3; mr 3,31; bl _s8009CECC_13; lwz 0,0x0(29); subf 5,26,3; add 30,30,26; subf 5,28,5; add 0,0,26; add 4,30,28; add 3,0,27; bl _s8009CECC_14; mr 3,31; bl _s8009CECC_15; lwz 30,0x0(29); add 30,30,3; add 30,30,27; subf 30,28,30; bl _s8009CECC_16; stb 3,0x0(30); mr 3,31; bl _s8009CECC_17; stw 3,0x4(29); mr 3,31; bl _s8009CECC_18; stw 29,0x0(31); b 7f; 3:; cmplw 27,28; bge 4f; mr 3,31; cmpwi 4,27,0; bl _s8009CECC_19; subf 25,28,27; mr 30,3; mr 3,31; bl _s8009CECC_20; mr 29,3; mr 3,31; bl _s8009CECC_21; subf 5,26,3; add 30,30,26; add 29,29,26; add 3,30,27; add 4,29,28; subf 5,28,5; bl _s8009CECC_22; b 6f; 4:; mr 3,31; cmpwi 4,27,0; bl _s8009CECC_23; subf 25,28,27; subf 3,26,3; subf. 29,28,3; beq 6f; 5:; mr 3,31; bl _s8009CECC_24; mr 30,3; mr 3,31; bl _s8009CECC_25; add 3,3,26; add 30,30,26; add 3,3,28; add 30,30,27; add 3,3,29; add 30,30,29; lbz 0,-1(3); addic. 29,29,-1; stb 0,-1(30); bne 5b; 6:; mr 3,31; bl _s8009CECC_26; mr 30,3; mr 3,31; bl _s8009CECC_27; add 30,30,3; add 30,30,27; subf 30,28,30; bl _s8009CECC_28; stb 3,0x0(30); 7:; beq cr4,8f; mr 3,31; bl _s8009CECC_29; add 3,3,26; mr 4,24; mr 5,27; bl _s8009CECC_30; 8:; lwz 9,0x0(31); lwz 0,0x4(9); add 0,0,25; stw 0,0x4(9); lwz 0,0x34(1); lwz 12,0xc(1); mtspr 8,0; lmw 24,0x10(1); mtcrf 8,12; addi 1,1,48"
extern "C" void _s8009CECC_0();
extern "C" void _s8009CECC_1();
extern "C" void _s8009CECC_2();
extern "C" void _s8009CECC_3();
extern "C" void _s8009CECC_4();
extern "C" void _s8009CECC_5();
extern "C" void _s8009CECC_6();
extern "C" void _s8009CECC_7();
extern "C" void _s8009CECC_8();
extern "C" void _s8009CECC_9();
extern "C" void _s8009CECC_10();
extern "C" void _s8009CECC_11();
extern "C" void _s8009CECC_12();
extern "C" void _s8009CECC_13();
extern "C" void _s8009CECC_14();
extern "C" void _s8009CECC_15();
extern "C" void _s8009CECC_16();
extern "C" void _s8009CECC_17();
extern "C" void _s8009CECC_18();
extern "C" void _s8009CECC_19();
extern "C" void _s8009CECC_20();
extern "C" void _s8009CECC_21();
extern "C" void _s8009CECC_22();
extern "C" void _s8009CECC_23();
extern "C" void _s8009CECC_24();
extern "C" void _s8009CECC_25();
extern "C" void _s8009CECC_26();
extern "C" void _s8009CECC_27();
extern "C" void _s8009CECC_28();
extern "C" void _s8009CECC_29();
extern "C" void _s8009CECC_30();
extern "C" void f_8009CECC() {}
