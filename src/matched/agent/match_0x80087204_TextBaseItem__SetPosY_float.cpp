// 0x80087204 TextBaseItem::SetPosY(float) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f1,0x28(3)"
extern "C" void f_80087204() {}
