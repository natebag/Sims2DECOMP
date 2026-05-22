// 0x800871F4 TextBaseItem::SetPosX(float) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f1,0x24(3)"
extern "C" void f_800871F4() {}
