// 0x802B837C AptScriptFunctionBase::SetupBeforeExecution(_AptScriptFunctionState (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-26960(13); li 9,0; stw 0,0x0(4); stw 9,-26960(13)"
extern "C" void f_802B837C() {}
