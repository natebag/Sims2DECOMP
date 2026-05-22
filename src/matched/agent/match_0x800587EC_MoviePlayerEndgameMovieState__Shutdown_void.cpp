// 0x800587EC MoviePlayerEndgameMovieState::Shutdown(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 3,-32697; addi 3,3,-7672; bl _s800587EC_0; lis 3,-32697; addi 3,3,23428; bl _s800587EC_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800587EC_0();
extern "C" void _s800587EC_1();
extern "C" void f_800587EC() {}
