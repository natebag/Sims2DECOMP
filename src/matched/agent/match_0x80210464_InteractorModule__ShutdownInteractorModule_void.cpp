// 0x80210464 InteractorModule::ShutdownInteractorModule(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s80210464_0; li 4,0; li 5,0; bl _s80210464_1; bl _s80210464_2; li 4,1; li 5,0; bl _s80210464_3; bl _s80210464_4; bl _s80210464_5; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80210464_0();
extern "C" void _s80210464_1();
extern "C" void _s80210464_2();
extern "C" void _s80210464_3();
extern "C" void _s80210464_4();
extern "C" void _s80210464_5();
extern "C" void f_80210464() {}
