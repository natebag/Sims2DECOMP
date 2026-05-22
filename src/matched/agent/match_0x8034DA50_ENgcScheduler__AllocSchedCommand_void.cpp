// 0x8034DA50 ENgcScheduler::AllocSchedCommand(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 4,-1; lwz 9,0x3a0(31); addi 0,31,928; lha 3,0x10(9); lwz 9,0x14(9); add 3,0,3; mtspr 8,9; blrl; lwz 30,0x394(31); addi 3,31,916; cmpwi 30,0; beq 0f; lwz 0,0x0(30); stw 0,0x394(31); b 1f; 0:; bl _s8034DA50_0; mr 30,3; 1:; lwz 9,0x3a0(31); addi 0,31,928; lha 3,0x18(9); lwz 9,0x1c(9); add 3,0,3; mtspr 8,9; blrl; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8034DA50_0();
extern "C" void f_8034DA50() {}
