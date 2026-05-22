// 0x802C6354 EFile::SetName(char (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-808(1); mfspr 0,8; stmw 27,0x314(1); stw 0,0x32c(1); mr 31,3; addi 30,1,528; mr 3,4; addi 5,1,16; addi 6,1,272; mr 28,5; mr 27,6; mr 7,30; addi 4,1,8; mr 29,30; bl _s802C6354_0; mr 3,30; bl _s802C6354_1; cmpwi 3,0; beq 0f; lbz 0,0x210(1); cmpwi 0,46; bne 0f; mr 3,29; addi 4,1,529; bl _s802C6354_2; 0:; addi 4,1,8; li 5,4; addi 3,31,24; li 30,0; bl _s802C6354_3; stb 30,0x1b(31); li 5,4; mr 4,29; addi 3,31,36; bl _s802C6354_4; stb 30,0x27(31); bl _s802C6354_5; lwz 4,0x1c(31); bl _s802C6354_6; mr 3,28; bl _s802C6354_7; stw 3,0x1c(31); bl _s802C6354_8; lwz 4,0x20(31); bl _s802C6354_9; mr 3,27; bl _s802C6354_10; stw 3,0x20(31); lwz 0,0x32c(1); mtspr 8,0; lmw 27,0x314(1); addi 1,1,808"
extern "C" void _s802C6354_0();
extern "C" void _s802C6354_1();
extern "C" void _s802C6354_2();
extern "C" void _s802C6354_3();
extern "C" void _s802C6354_4();
extern "C" void _s802C6354_5();
extern "C" void _s802C6354_6();
extern "C" void _s802C6354_7();
extern "C" void _s802C6354_8();
extern "C" void _s802C6354_9();
extern "C" void _s802C6354_10();
extern "C" void f_802C6354() {}
