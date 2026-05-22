// 0x80093118 MUStatesLoadConfig::Reset(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x1c(3)"
extern "C" void f_80093118() {}
