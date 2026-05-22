// 0x8008395C MUWrapper::SetBackgroundDrawEnable(bool) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0xc8(3)"
extern "C" void f_8008395C() {}
