// 0x801C2E28 M2MTarget::PrepareNewGame(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 0,1; li 9,5; lis 3,-32705; stw 0,0x180(30); addi 3,3,8412; stw 9,0x11c(30); li 4,7; bl _s801C2E28_0; li 0,3; stw 0,0x168(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801C2E28_0();
extern "C" void f_801C2E28() {}
