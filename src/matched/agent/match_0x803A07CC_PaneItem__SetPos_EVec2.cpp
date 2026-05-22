// 0x803A07CC PaneItem::SetPos(EVec2 (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(4); lwz 9,0x0(4); stw 0,0x10(3); stw 9,0xc(3)"
extern "C" void f_803A07CC() {}
