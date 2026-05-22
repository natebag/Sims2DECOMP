// 0x801430BC SpriteSlot::AlternateWithSprite(int, (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x48(3); stw 4,0x1c(3); ori 0,0,64; stw 5,0x20(3); stw 0,0x48(3)"
extern "C" void f_801430BC() {}
