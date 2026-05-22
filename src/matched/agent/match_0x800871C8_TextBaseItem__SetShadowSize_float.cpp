// 0x800871C8 TextBaseItem::SetShadowSize(float) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f1,0x4c(3)"
extern "C" void f_800871C8() {}
