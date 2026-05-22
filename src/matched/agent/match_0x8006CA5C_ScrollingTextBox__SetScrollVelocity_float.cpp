// 0x8006CA5C ScrollingTextBox::SetScrollVelocity(float, (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f2,0x18(3); stfs f1,0x14(3)"
extern "C" void f_8006CA5C() {}
