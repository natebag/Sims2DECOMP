// 0x801C028C ObjSelector::GetAdultToChildAnimTable(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 5,29; bl _s801C028C_0; mr 3,29; bl _s801C028C_1; mr 3,29; bl _s801C028C_2; mr 3,29; bl _s801C028C_3; mr 3,29; bl _s801C028C_4; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801C028C_5; mr 30,3; mr 4,29; bl _s801C028C_6; mr 3,29; bl _s801C028C_7; mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s801C028C_0();
extern "C" void _s801C028C_1();
extern "C" void _s801C028C_2();
extern "C" void _s801C028C_3();
extern "C" void _s801C028C_4();
extern "C" void _s801C028C_5();
extern "C" void _s801C028C_6();
extern "C" void _s801C028C_7();
extern "C" int f_801C028C() {}
