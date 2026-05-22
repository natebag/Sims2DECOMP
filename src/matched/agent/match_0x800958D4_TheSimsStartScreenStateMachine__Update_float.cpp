// 0x800958D4 TheSimsStartScreenStateMachine::Update(float) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stmw 30,0x8(1); stw 0,0x1c(1); mr 30,3; fmr f31,f1; lwz 3,-24644(13); bl _s800958D4_0; mr 3,30; fmr f1,f31; bl _s800958D4_1; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x8(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s800958D4_0();
extern "C" void _s800958D4_1();
extern "C" void f_800958D4() {}
