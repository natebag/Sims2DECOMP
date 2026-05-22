// 0x80036EA0 ESpriteRenderMan::ESpriteRenderMan(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; li 11,0; li 0,1; stw 11,0x0(9); stw 0,0x8(9); stw 11,0x4(9)"
extern "C" void f_80036EA0() {}
