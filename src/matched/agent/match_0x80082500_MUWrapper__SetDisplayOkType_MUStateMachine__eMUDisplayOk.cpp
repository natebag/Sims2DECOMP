// 0x80082500 MUWrapper::SetDisplayOkType(MUStateMachine::eMUDisplayOk) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 4,0xb4(3); stw 0,0xbc(3); stw 0,0xb8(3)"
extern "C" void f_80082500() {}
