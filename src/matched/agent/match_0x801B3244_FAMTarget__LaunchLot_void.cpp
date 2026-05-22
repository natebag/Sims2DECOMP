// 0x801B3244 FAMTarget::LaunchLot(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 4,0x14c(3); bl _s801B3244_0; mr 4,3; lis 3,-32697; addi 3,3,-7672; bl _s801B3244_1; lis 3,-32705; addi 3,3,1940; bl _s801B3244_2; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801B3244_0();
extern "C" void _s801B3244_1();
extern "C" void _s801B3244_2();
extern "C" void f_801B3244() {}
