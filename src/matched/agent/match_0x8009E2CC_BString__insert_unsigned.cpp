// 0x8009E2CC BString::insert(unsigned (532 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 31,3; mr 28,4; stb 5,0x8(1); mr 27,6; bl _s8009E2CC_0; cmplw 28,3; ble 0f; bl _s8009E2CC_1; 0:; cmpwi 27,-1; beq 1f; mr 3,31; bl _s8009E2CC_2; not 0,27; cmplw 3,0; blt 2f; 1:; bl _s8009E2CC_3; 2:; cmpwi 27,0; beq 12f; mr 3,31; bl _s8009E2CC_4; cmplwi 3,1; bgt 3f; mr 3,31; bl _s8009E2CC_5; mr 30,3; mr 3,31; bl _s8009E2CC_6; add 3,3,27; addi 3,3,1; cmplw 30,3; bge 6f; 3:; bl _s8009E2CC_7; li 4,16; li 5,0; bl _s8009E2CC_8; mr 29,3; mr 3,31; bl _s8009E2CC_9; mr 30,3; mr 3,31; bl _s8009E2CC_10; add 6,3,27; mr 4,30; mr 5,28; mr 3,29; bl _s8009E2CC_11; mr 26,3; mr 3,31; bl _s8009E2CC_12; cmpwi 3,0; beq 5f; mr 3,31; bl _s8009E2CC_13; subf. 29,28,3; beq 5f; 4:; mr 3,31; bl _s8009E2CC_14; lwz 9,0x0(26); add 3,3,28; add 3,3,29; add 9,9,28; lbz 0,-1(3); add 9,9,27; add 9,9,29; stb 0,-1(9); addic. 29,29,-1; bne 4b; 5:; mr 3,31; bl _s8009E2CC_15; mr 30,3; bl _s8009E2CC_16; lwz 9,0x0(26); add 9,9,30; stbx 3,9,27; mr 3,31; bl _s8009E2CC_17; stw 3,0x4(26); mr 3,31; bl _s8009E2CC_18; stw 26,0x0(31); b 9f; 6:; mr 3,31; bl _s8009E2CC_19; subf. 29,28,3; beq 8f; 7:; mr 3,31; bl _s8009E2CC_20; mr 30,3; mr 3,31; bl _s8009E2CC_21; add 3,3,28; add 30,30,28; add 3,3,29; add 30,30,27; lbz 0,-1(3); add 30,30,29; addic. 29,29,-1; stb 0,-1(30); bne 7b; 8:; mr 3,31; bl _s8009E2CC_22; mr 30,3; mr 3,31; bl _s8009E2CC_23; mr 29,3; bl _s8009E2CC_24; add 30,30,27; stbx 3,30,29; 9:; li 29,0; cmplw 29,27; bge 11f; 10:; mr 3,31; bl _s8009E2CC_25; lbz 0,0x8(1); add 3,3,28; stbx 0,3,29; addi 29,29,1; cmplw 29,27; blt 10b; 11:; lwz 9,0x0(31); lwz 0,0x4(9); add 0,0,27; stw 0,0x4(9); 12:; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s8009E2CC_0();
extern "C" void _s8009E2CC_1();
extern "C" void _s8009E2CC_2();
extern "C" void _s8009E2CC_3();
extern "C" void _s8009E2CC_4();
extern "C" void _s8009E2CC_5();
extern "C" void _s8009E2CC_6();
extern "C" void _s8009E2CC_7();
extern "C" void _s8009E2CC_8();
extern "C" void _s8009E2CC_9();
extern "C" void _s8009E2CC_10();
extern "C" void _s8009E2CC_11();
extern "C" void _s8009E2CC_12();
extern "C" void _s8009E2CC_13();
extern "C" void _s8009E2CC_14();
extern "C" void _s8009E2CC_15();
extern "C" void _s8009E2CC_16();
extern "C" void _s8009E2CC_17();
extern "C" void _s8009E2CC_18();
extern "C" void _s8009E2CC_19();
extern "C" void _s8009E2CC_20();
extern "C" void _s8009E2CC_21();
extern "C" void _s8009E2CC_22();
extern "C" void _s8009E2CC_23();
extern "C" void _s8009E2CC_24();
extern "C" void _s8009E2CC_25();
extern "C" void f_8009E2CC() {}
