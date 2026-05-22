// 0x800871A0 TextBaseItem::SetAlpha(float) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x44(3); stfs f1,0xc(9)"
extern "C" void f_800871A0() {}
