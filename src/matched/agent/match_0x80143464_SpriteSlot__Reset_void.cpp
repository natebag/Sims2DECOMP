// 0x80143464 SpriteSlot::Reset(void) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32706; lfs f13,0x4c(3); lfs f0,-10444(9); li 0,0; stw 0,0x10(3); stfs f0,0x5c(3); stfs f13,0xc(3); stw 0,0x18(3); stw 0,0x1c(3); stw 0,0x48(3); stfs f0,0x50(3); stfs f0,0x54(3); stfs f0,0x58(3)"
extern "C" void f_80143464() {}
