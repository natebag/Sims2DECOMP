// 0x802092C8 SpriteSlot::Deactivate(void) (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x50(3); stw 0,0xc(4); stw 9,0x8(4); blr; lwz 0,0x4(4); lwz 9,0x0(4); stw 0,0x54(3); stw 9,0x50(3)"
extern "C" void f_802092C8() {}
