// 0x8005871C MoviePlayerEndgameMovieState::Update(float) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lis 31,-32697; addi 3,31,-7672; bl _s8005871C_0; cmpwi 3,0; bne 0f; addi 3,31,-7672; bl _s8005871C_1; cmpwi 3,0; bne 0f; lwz 3,-21492(13); bl _s8005871C_2; mr 3,30; bl _s8005871C_3; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8005871C_0();
extern "C" void _s8005871C_1();
extern "C" void _s8005871C_2();
extern "C" void _s8005871C_3();
extern "C" void f_8005871C() {}
