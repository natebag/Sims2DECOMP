// 0x801C1D70 M2MTarget::StartLoadedGame(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; lis 9,-32697; lwz 0,0x114(29); addi 9,9,24012; li 30,0; stw 0,0x448(9); stw 30,0x44c(9); bl _s801C1D70_0; sth 30,0xce(29); lis 3,-32705; stw 30,0xc0(29); li 4,5; sth 30,0xcc(29); addi 3,3,8412; bl _s801C1D70_1; mr 3,29; bl _s801C1D70_2; li 0,3; stw 0,0x168(29); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801C1D70_0();
extern "C" void _s801C1D70_1();
extern "C" void _s801C1D70_2();
extern "C" void f_801C1D70() {}
