// 0x80036E70 ESpriteRender::GetObject(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x8(3)"
extern "C" int f_80036E70() {}
