// 0x802769BC AptActionInterpreter::_FunctionAptActionReturn(AptActionInterpreter (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 0,0x14(4)"
extern "C" void f_802769BC() {}
