// 0x800972E8 TheSimsEAMovieState::Update(float) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lis 31,-32697; addi 3,31,-7672; bl _s800972E8_0; cmpwi 3,0; bne 0f; addi 3,31,-7672; bl _s800972E8_1; cmpwi 3,0; bne 0f; lis 9,-32706; mr 3,30; lfs f1,-29804(9); li 4,3; bl _s800972E8_2; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800972E8_0();
extern "C" void _s800972E8_1();
extern "C" void _s800972E8_2();
extern "C" void f_800972E8() {}
