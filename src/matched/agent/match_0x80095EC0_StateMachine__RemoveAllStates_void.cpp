// 0x80095EC0 StateMachine::RemoveAllStates(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; addi 30,29,60; mr 3,30; bl _s80095EC0_0; lis 9,-32706; li 0,0; lfs f0,-30552(9); stw 0,0x4(30); stfs f0,0x10(30); lwz 0,0x2c(29); stw 0,0x30(29); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80095EC0_0();
extern "C" void f_80095EC0() {}
