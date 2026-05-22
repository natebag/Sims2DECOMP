// 0x800370D8 ESpriteRenderMan::SetSprite(SpriteSlot (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); cmpwi 3,0; beqlr; lwz 11,0x0(3); lwz 0,0x64(4); lwz 9,0x8(11); mr 10,0; cmpw 9,0; bne 0f; li 0,1; stw 0,0x4(11); blr; 0:; lwz 3,0x8(3); cmpwi 3,0; beqlr; lwz 9,0x0(3); lwz 0,0x8(9); cmpw 0,10; bne 0b; li 0,1; stw 0,0x4(9)"
extern "C" void f_800370D8() {}
