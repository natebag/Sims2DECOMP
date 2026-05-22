// 0x801830A8 ActionMenu::MenuItem::AddItem(ActionMenu::MenuItem (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x60(3); stw 0,0x60(4); stw 4,0x60(3)"
extern "C" void f_801830A8() {}
