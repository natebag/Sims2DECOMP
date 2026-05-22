// 0x800871D8 TextBaseItem::SetPos(EVec2 (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(4); lwz 9,0x0(4); stw 0,0x28(3); stw 9,0x24(3)"
extern "C" void f_800871D8() {}
