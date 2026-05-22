// 0x80087198 TextBaseItem::GetColor(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x44(3)"
extern "C" int f_80087198() {}
