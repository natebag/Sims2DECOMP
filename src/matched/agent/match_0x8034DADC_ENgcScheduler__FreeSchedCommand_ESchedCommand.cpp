// 0x8034DADC ENgcScheduler::FreeSchedCommand(ESchedCommand (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 9,0x3a0(31); addi 29,31,928; li 4,-1; lha 3,0x10(9); lwz 0,0x14(9); add 3,29,3; mtspr 8,0; blrl; cmpwi 30,0; beq 0f; lwz 0,0x394(31); stw 0,0x0(30); stw 30,0x394(31); 0:; lwz 9,0x3a0(31); lha 3,0x18(9); lwz 0,0x1c(9); add 3,29,3; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_8034DADC() {}
