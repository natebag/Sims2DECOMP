// 0x800878A4 IconItem::SetAlpha(float) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f1,0x2c(3)"
extern "C" void f_800878A4() {}
