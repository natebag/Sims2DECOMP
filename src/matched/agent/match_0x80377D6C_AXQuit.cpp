// 0x80377D6C AXQuit (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s80377D6C_0; bl _s80377D6C_1; bl _s80377D6C_2; bl _s80377D6C_3; bl _s80377D6C_4; bl _s80377D6C_5; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80377D6C_0();
extern "C" void _s80377D6C_1();
extern "C" void _s80377D6C_2();
extern "C" void _s80377D6C_3();
extern "C" void _s80377D6C_4();
extern "C" void _s80377D6C_5();
extern "C" void f_80377D6C() {}
