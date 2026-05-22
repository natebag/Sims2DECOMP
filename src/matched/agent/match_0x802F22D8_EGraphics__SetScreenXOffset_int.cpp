// 0x802F22D8 EGraphics::SetScreenXOffset(int) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x20(3)"
extern "C" void f_802F22D8() {}
