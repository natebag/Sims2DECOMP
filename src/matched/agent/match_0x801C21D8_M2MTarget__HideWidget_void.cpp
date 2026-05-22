// 0x801C21D8 M2MTarget::HideWidget(void) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); li 0,0; addi 30,3,288; stw 0,0x168(3); mr 3,30; bl _s801C21D8_0; lis 4,-32705; li 5,0; addi 4,4,9056; mr 3,30; bl _s801C21D8_1; li 4,0; mr 3,30; bl _s801C21D8_2; lis 4,-32705; li 5,0; addi 4,4,9060; mr 3,30; bl _s801C21D8_3; li 4,0; mr 3,30; bl _s801C21D8_4; lis 4,-32705; mr 3,30; addi 4,4,9072; li 5,0; bl _s801C21D8_5; mr 3,30; li 4,0; bl _s801C21D8_6; mr 3,30; bl _s801C21D8_7; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801C21D8_0();
extern "C" void _s801C21D8_1();
extern "C" void _s801C21D8_2();
extern "C" void _s801C21D8_3();
extern "C" void _s801C21D8_4();
extern "C" void _s801C21D8_5();
extern "C" void _s801C21D8_6();
extern "C" void _s801C21D8_7();
extern "C" void f_801C21D8() {}
