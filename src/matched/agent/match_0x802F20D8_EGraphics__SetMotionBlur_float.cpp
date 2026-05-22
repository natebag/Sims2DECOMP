// 0x802F20D8 EGraphics::SetMotionBlur(float, (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f4,0x2fc(3); stfs f1,0x2f0(3); stfs f2,0x2f4(3); stfs f3,0x2f8(3)"
extern "C" void f_802F20D8() {}
