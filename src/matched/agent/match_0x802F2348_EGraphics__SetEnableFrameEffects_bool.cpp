// 0x802F2348 EGraphics::SetEnableFrameEffects(bool) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x320(3)"
extern "C" void f_802F2348() {}
