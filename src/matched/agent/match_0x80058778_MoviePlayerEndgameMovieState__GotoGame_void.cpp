// 0x80058778 MoviePlayerEndgameMovieState::GotoGame(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); li 0,0; lis 9,-32697; mr 30,3; stw 0,0x5f24(9); li 3,4; bl _s80058778_0; lis 3,-32697; addi 3,3,23428; bl _s80058778_1; lis 9,-32707; mr 3,30; lfs f1,0x3dd8(9); li 4,13; bl _s80058778_2; lis 3,-32707; addi 3,3,15824; bl _s80058778_3; lwz 3,0x8(30); bl _s80058778_4; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80058778_0();
extern "C" void _s80058778_1();
extern "C" void _s80058778_2();
extern "C" void _s80058778_3();
extern "C" void _s80058778_4();
extern "C" void f_80058778() {}
