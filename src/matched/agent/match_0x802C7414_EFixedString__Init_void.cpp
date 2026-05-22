// 0x802C7414 EFixedString::Init(void (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 5,0x4(3); li 0,0; stw 4,0x0(3); stb 0,0x0(4)"
extern "C" void f_802C7414() {}
