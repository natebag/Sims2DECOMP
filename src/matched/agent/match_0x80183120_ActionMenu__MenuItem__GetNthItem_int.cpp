// 0x80183120 ActionMenu::MenuItem::GetNthItem(int) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 0,4; mtspr 9,0; beqlr; 0:; lwz 3,0x60(3); bdnz 0b"
extern "C" int f_80183120() {}
