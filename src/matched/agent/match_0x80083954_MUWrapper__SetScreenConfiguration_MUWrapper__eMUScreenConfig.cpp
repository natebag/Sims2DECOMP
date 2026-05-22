// 0x80083954 MUWrapper::SetScreenConfiguration(MUWrapper::eMUScreenConfiguration) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0xac(3)"
extern "C" void f_80083954() {}
