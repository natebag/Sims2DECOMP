// 0x80095D78 StateMachine::SetNextState(int, (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stw 31,0xc(1); stw 0,0x1c(1); mr 31,3; fmr f31,f1; bl _s80095D78_0; mr. 3,3; beq 0f; addi 9,31,60; stfs f31,0x10(9); stw 3,0x4(9); 0:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0xc(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s80095D78_0();
extern "C" void f_80095D78() {}
