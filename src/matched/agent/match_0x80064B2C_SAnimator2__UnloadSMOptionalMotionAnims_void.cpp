// 0x80064B2C SAnimator2::UnloadSMOptionalMotionAnims(void) (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; lwz 0,0x61c(30); andis. 9,0,512; beq 4f; lbz 9,0x5f9(30); rlwinm 0,0,0,7,5; stw 0,0x61c(30); cmpwi 9,5; bne 0f; lwz 3,0x4(30); addi 5,1,8; li 4,18; lis 31,-32693; bl _s80064B2C_0; lwz 9,0x8(1); addi 3,31,11064; lwz 4,0x0(9); bl _s80064B2C_1; cmpwi 3,0; bne 1f; lwz 9,0x8(1); addi 3,31,11064; lwz 4,0x0(9); bl _s80064B2C_2; b 3f; 0:; cmpwi 9,9; bne 3f; lwz 3,0x4(30); addi 5,1,8; li 4,59; lis 31,-32693; bl _s80064B2C_3; lwz 9,0x8(1); addi 3,31,11064; lwz 4,0x0(9); bl _s80064B2C_4; cmpwi 3,0; beq 2f; 1:; lwz 9,0x8(1); addi 3,31,11064; li 5,1; lwz 4,0x0(9); bl _s80064B2C_5; b 3f; 2:; lwz 9,0x8(1); addi 3,31,11064; lwz 4,0x0(9); bl _s80064B2C_6; 3:; li 0,0; stb 0,0x5f9(30); 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s80064B2C_0();
extern "C" void _s80064B2C_1();
extern "C" void _s80064B2C_2();
extern "C" void _s80064B2C_3();
extern "C" void _s80064B2C_4();
extern "C" void _s80064B2C_5();
extern "C" void _s80064B2C_6();
extern "C" void f_80064B2C() {}
