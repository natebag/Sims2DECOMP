// 0x802F2334 EGraphics::EnableNormalRender(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x31c(3)"
extern "C" void f_802F2334() {}
