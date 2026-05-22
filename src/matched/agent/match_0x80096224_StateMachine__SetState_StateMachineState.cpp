// 0x80096224 StateMachine::SetState(StateMachineState (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; addi 3,30,60; bl _s80096224_0; li 0,0; stw 0,0x90(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80096224_0();
extern "C" void f_80096224() {}
