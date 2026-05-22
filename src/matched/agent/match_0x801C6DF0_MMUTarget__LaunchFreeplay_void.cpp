// 0x801C6DF0 MMUTarget::LaunchFreeplay(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; li 0,1; addi 9,9,23428; mr 30,3; mr 3,9; stw 0,0xe4(9); stw 0,0x84(9); li 4,0; bl _s801C6DF0_0; lis 3,-32705; addi 3,3,11580; bl _s801C6DF0_1; li 0,0; mr 3,30; stw 0,0x8c(30); bl _s801C6DF0_2; mr 3,30; bl _s801C6DF0_3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801C6DF0_0();
extern "C" void _s801C6DF0_1();
extern "C" void _s801C6DF0_2();
extern "C" void _s801C6DF0_3();
extern "C" void f_801C6DF0() {}
