// 0x8027DAAC AptActionInterpreter::_FunctionAptActionDefineDictionary(AptActionInterpreter (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x0(4); addi 11,11,3; clrlwi 11,11,29; addi 0,11,8; stw 0,0x0(4); lwz 9,0x0(11); lwz 10,0x4(11); stw 9,0x34(3); stw 10,0x38(3)"
extern "C" void f_8027DAAC() {}
