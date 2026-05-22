// 0x8013EDD8 LogInteraction::LogInteraction(LogPersonTracker (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 31,3; mr 30,4; addi 29,31,8; addi 27,31,12; mr 3,29; bl _s8013EDD8_0; mr 3,27; bl _s8013EDD8_1; li 0,0; addi 9,31,24; stw 0,0x10(31); stw 0,0x14(31); stw 0,0x4(9); lwz 11,-21508(13); lwz 4,0x8(30); stw 4,0x0(31); lwz 0,0x10(30); stw 0,0x4(31); lwz 9,0x0(11); lha 3,0x78(9); lwz 0,0x7c(9); add 3,11,3; mtspr 8,0; blrl; mr. 28,3; beq 1f; addi 30,1,16; mr 3,28; bl _s8013EDD8_2; mr 4,3; mr 3,30; crxor 6,6,6; bl _s8013EDD8_3; lwz 9,0x10(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,29; bl _s8013EDD8_4; mr 3,28; bl _s8013EDD8_5; mr. 11,3; beq 2f; lwz 9,0x0(11); lwz 4,0x4(31); lha 3,0x88(9); lwz 0,0x8c(9); add 3,11,3; mtspr 8,0; blrl; mr. 11,3; beq 2f; lwz 9,0x0(11); lha 3,0x1a0(9); lwz 0,0x1a4(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; mr 3,27; bl _s8013EDD8_6; b 2f; 1:; lis 4,-32706; mr 3,29; addi 4,4,-10996; bl _s8013EDD8_7; lis 4,-32706; mr 3,27; addi 4,4,-10984; bl _s8013EDD8_8; 2:; mr 3,31; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s8013EDD8_0();
extern "C" void _s8013EDD8_1();
extern "C" void _s8013EDD8_2();
extern "C" void _s8013EDD8_3();
extern "C" void _s8013EDD8_4();
extern "C" void _s8013EDD8_5();
extern "C" void _s8013EDD8_6();
extern "C" void _s8013EDD8_7();
extern "C" void _s8013EDD8_8();
extern "C" void f_8013EDD8() {}
