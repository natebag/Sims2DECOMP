// 0x800B81F8 Globs::Startup(void) (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32696; addi 9,9,24120; stw 9,-21356(13); bl _s800B81F8_0; stw 3,-21412(13); bl _s800B81F8_1; lwz 9,0x0(3); lis 4,-32706; stw 3,-21508(13); li 5,1; lha 0,0x10(9); addi 4,4,-25760; lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; bl _s800B81F8_2; bl _s800B81F8_3; stw 3,-21476(13); bl _s800B81F8_4; lwz 9,0x0(3); stw 3,-21424(13); lha 0,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; li 3,32; bl _s800B81F8_5; bl _s800B81F8_6; mr 0,3; stw 0,-21492(13); bl _s800B81F8_7; li 4,0; li 3,141; bl _s800B81F8_8; bl _s800B81F8_9; mulli 0,3,60; lis 3,4194; ori 3,3,19923; mulhw 3,0,3; srawi 0,0,31; srawi 3,3,6; subf 3,0,3; bl _s800B81F8_10; li 3,132; li 4,0; bl _s800B81F8_11; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800B81F8_0();
extern "C" void _s800B81F8_1();
extern "C" void _s800B81F8_2();
extern "C" void _s800B81F8_3();
extern "C" void _s800B81F8_4();
extern "C" void _s800B81F8_5();
extern "C" void _s800B81F8_6();
extern "C" void _s800B81F8_7();
extern "C" void _s800B81F8_8();
extern "C" void _s800B81F8_9();
extern "C" void _s800B81F8_10();
extern "C" void _s800B81F8_11();
extern "C" void f_800B81F8() {}
