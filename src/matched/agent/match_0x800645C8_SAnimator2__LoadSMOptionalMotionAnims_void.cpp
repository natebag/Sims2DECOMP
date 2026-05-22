// 0x800645C8 SAnimator2::LoadSMOptionalMotionAnims(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; lwz 0,0x61c(31); andis. 9,0,64; beq 0f; bl _s800645C8_0; 0:; lwz 0,0x61c(31); andis. 9,0,512; bne 2f; mr 3,31; bl _s800645C8_1; rlwinm 9,3,0,24,31; stb 3,0x5f9(31); cmpwi 9,0; beq 2f; lwz 0,0x61c(31); cmpwi 9,5; oris 0,0,512; stw 0,0x61c(31); bne 1f; lwz 3,0x4(31); li 4,18; addi 5,1,8; bl _s800645C8_2; lwz 9,0x8(1); lis 3,-32693; addi 3,3,11064; lwz 4,0x0(9); bl _s800645C8_3; b 2f; 1:; cmpwi 9,9; bne 2f; lwz 3,0x4(31); li 4,59; addi 5,1,8; bl _s800645C8_4; lwz 9,0x8(1); lis 3,-32693; addi 3,3,11064; lwz 4,0x0(9); bl _s800645C8_5; 2:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s800645C8_0();
extern "C" void _s800645C8_1();
extern "C" void _s800645C8_2();
extern "C" void _s800645C8_3();
extern "C" void _s800645C8_4();
extern "C" void _s800645C8_5();
extern "C" void f_800645C8() {}
