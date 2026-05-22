// 0x80350B84 InteractorModule::DirectInteractor::ResetIdleTime(void) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 6,0; fmr f3,f2; li 7,0; li 8,0; bl _s80350B84_0; bl _s80350B84_1; addi 30,31,72; stw 3,0x94(31); addi 29,31,156; bl _s80350B84_2; stw 3,0xc8(31); lwz 4,0x94(31); mr 3,30; bl _s80350B84_3; lwz 4,0x94(31); addi 3,31,132; bl _s80350B84_4; lwz 4,0xc8(31); mr 3,29; bl _s80350B84_5; lwz 4,0xc8(31); addi 3,31,188; bl _s80350B84_6; mr 3,30; mr 4,26; bl _s80350B84_7; mr 3,29; addi 4,26,1; bl _s80350B84_8; lwz 0,0x3c(1); mtspr 8,0; lmw 26,0x18(1); lfd f31,0x30(1); addi 1,1,56; blr; li 3,2; blr; li 3,2; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 4,3; li 5,8; lis 3,-32692; addi 3,3,-7364; bl _s80350B84_9; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; mr 3,4"
extern "C" void _s80350B84_0();
extern "C" void _s80350B84_1();
extern "C" void _s80350B84_2();
extern "C" void _s80350B84_3();
extern "C" void _s80350B84_4();
extern "C" void _s80350B84_5();
extern "C" void _s80350B84_6();
extern "C" void _s80350B84_7();
extern "C" void _s80350B84_8();
extern "C" void _s80350B84_9();
extern "C" void f_80350B84() {}
