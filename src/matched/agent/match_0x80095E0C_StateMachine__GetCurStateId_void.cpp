// 0x80095E0C StateMachine::GetCurStateId(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x3c(3); cmpwi 3,0; bne 0f; li 3,-1; blr; 0:; lwz 3,0x0(3)"
extern "C" int f_80095E0C() {}
