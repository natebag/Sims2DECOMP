// 0x800E9620 TextBaseItem::GetFontSize(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_800E9630" lines="bl _s800E9620_0"
extern "C" void _s800E9620_0();
extern "C" void f_800E9630();
extern "C" void f_800E9620() {}
