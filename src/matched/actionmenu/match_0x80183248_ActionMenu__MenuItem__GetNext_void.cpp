// 0x80183248 ActionMenu::MenuItem::GetNext(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x60(3)"
extern "C" int f_80183248() {}
