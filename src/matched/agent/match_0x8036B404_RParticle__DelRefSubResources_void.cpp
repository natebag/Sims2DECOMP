// 0x8036B404 RParticle::DelRefSubResources(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 27,3; lwz 9,0x14(27); cmpwi 9,0; beq 2f; lwz 0,0x18(27); li 28,0; cmpw 28,0; bge 2f; addi 29,9,364; li 26,0; addi 31,27,28; 0:; lwz 0,0x0(31); cmpwi 0,0; beq 1f; lwz 9,0x0(29); lwz 30,0x8(9); mr 3,9; bl _s8036B404_0; stw 26,0x0(31); stw 30,0x0(29); 1:; lwz 0,0x18(27); addi 28,28,1; addi 29,29,132; addi 31,31,4; cmpw 28,0; blt 0b; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8036B404_0();
extern "C" void f_8036B404() {}
