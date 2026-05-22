// 0x8009DE40 BString::append(char, (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,3; mr 27,5; stb 4,0x8(1); bl _s8009DE40_0; not 0,27; cmplw 3,0; blt 0f; bl _s8009DE40_1; 0:; cmpwi 27,0; beq 5f; mr 3,31; bl _s8009DE40_2; cmplwi 3,1; bgt 1f; mr 3,31; bl _s8009DE40_3; mr 30,3; mr 3,31; bl _s8009DE40_4; add 3,3,27; addi 3,3,1; cmplw 30,3; bge 2f; 1:; bl _s8009DE40_5; li 4,16; li 5,0; bl _s8009DE40_6; mr 28,3; mr 3,31; bl _s8009DE40_7; mr 29,3; mr 3,31; bl _s8009DE40_8; mr 30,3; mr 3,31; bl _s8009DE40_9; add 6,3,27; mr 5,30; mr 4,29; mr 3,28; bl _s8009DE40_10; mr 30,3; mr 3,31; bl _s8009DE40_11; stw 30,0x0(31); 2:; li 29,0; cmplw 29,27; bge 4f; 3:; mr 3,31; bl _s8009DE40_12; mr 30,3; mr 3,31; bl _s8009DE40_13; lbz 0,0x8(1); add 30,30,3; stbx 0,30,29; addi 29,29,1; cmplw 29,27; blt 3b; 4:; mr 3,31; bl _s8009DE40_14; mr 30,3; mr 3,31; bl _s8009DE40_15; mr 29,3; bl _s8009DE40_16; add 30,30,29; stbx 3,30,27; lwz 9,0x0(31); lwz 0,0x4(9); add 0,0,27; stw 0,0x4(9); 5:; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s8009DE40_0();
extern "C" void _s8009DE40_1();
extern "C" void _s8009DE40_2();
extern "C" void _s8009DE40_3();
extern "C" void _s8009DE40_4();
extern "C" void _s8009DE40_5();
extern "C" void _s8009DE40_6();
extern "C" void _s8009DE40_7();
extern "C" void _s8009DE40_8();
extern "C" void _s8009DE40_9();
extern "C" void _s8009DE40_10();
extern "C" void _s8009DE40_11();
extern "C" void _s8009DE40_12();
extern "C" void _s8009DE40_13();
extern "C" void _s8009DE40_14();
extern "C" void _s8009DE40_15();
extern "C" void _s8009DE40_16();
extern "C" void f_8009DE40() {}
