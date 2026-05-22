// 0x8036B55C RParticle::TryIncrementSubResources(void) (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,3; lwz 27,0x14(29); cmpwi 27,0; beq 9f; lwz 0,0x108(27); li 28,0; andis. 9,0,32; beq 0f; lis 3,-32692; lwz 4,0x16c(27); addi 3,3,-27556; addi 5,29,28; bl _s8036B55C_0; cmpwi 3,0; beq 7f; b 8f; 0:; andis. 9,0,512; beq 6f; lwz 0,0x18(29); li 30,0; cmpw 28,0; mr 9,0; bge 4f; lis 26,-32692; addi 31,29,28; addi 4,27,364; 1:; mr 28,4; addi 3,26,-27556; lwz 4,0x0(28); mr 5,31; bl _s8036B55C_1; cmpwi 3,0; bne 3f; addic. 30,30,-1; blt 7f; rlwinm 9,30,2,0,29; li 28,0; addi 9,9,28; add 31,9,29; 2:; lwz 3,0x0(31); bl _s8036B55C_2; stw 28,0x0(31); addic. 30,30,-1; addi 31,31,-4; bge 2b; b 7f; 3:; lwz 0,0x18(29); addi 30,30,1; addi 4,28,132; addi 31,31,4; mr 9,0; cmpw 30,0; blt 1b; 4:; li 10,0; cmpw 10,9; bge 9f; addi 11,27,364; addi 9,29,28; 5:; lwz 0,0x0(9); addi 10,10,1; addi 9,9,4; stw 0,0x0(11); addi 11,11,132; lwz 0,0x18(29); cmpw 10,0; blt 5b; b 9f; 6:; lis 3,-32692; lwz 4,0x16c(27); addi 3,3,-17444; addi 5,29,28; bl _s8036B55C_3; cmpwi 3,0; bne 8f; 7:; li 3,0; b 10f; 8:; lwz 0,0x1c(29); stw 0,0x16c(27); 9:; li 3,1; 10:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8036B55C_0();
extern "C" void _s8036B55C_1();
extern "C" void _s8036B55C_2();
extern "C" void _s8036B55C_3();
extern "C" void f_8036B55C() {}
