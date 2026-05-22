// 0x8006CBDC ScrollingTextBox::SetSubOffset(float, (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f2,0x38(3); stfs f1,0x34(3)"
extern "C" void f_8006CBDC() {}
