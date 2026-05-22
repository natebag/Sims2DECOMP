// 0x800871B8 TextBaseItem::SetShadowAlpha(float) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f1,0x48(3)"
extern "C" void f_800871B8() {}
