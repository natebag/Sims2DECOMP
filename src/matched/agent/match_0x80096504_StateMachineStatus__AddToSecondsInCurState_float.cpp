// 0x80096504 StateMachineStatus::AddToSecondsInCurState(float) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,0x14(3); fadds f0,f0,f1; stfs f0,0x14(3)"
extern "C" void f_80096504() {}
