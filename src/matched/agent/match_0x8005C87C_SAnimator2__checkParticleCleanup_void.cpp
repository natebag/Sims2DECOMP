// 0x8005C87C SAnimator2::checkParticleCleanup(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x61c(31); andis. 9,0,1; beq 0f; addi 4,31,1488; bl _s8005C87C_0; lwz 0,0x61c(31); rlwinm 0,0,0,16,14; stw 0,0x61c(31); 0:; lwz 0,0x61c(31); andis. 9,0,2; beq 1f; mr 3,31; addi 4,31,1500; bl _s8005C87C_1; lwz 0,0x61c(31); rlwinm 0,0,0,15,13; stw 0,0x61c(31); 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8005C87C_0();
extern "C" void _s8005C87C_1();
extern "C" void f_8005C87C() {}
