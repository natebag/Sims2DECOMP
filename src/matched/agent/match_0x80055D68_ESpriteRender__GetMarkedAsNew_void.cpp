// 0x80055D68 ESpriteRender::GetMarkedAsNew(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f11,0x8(3)"
extern "C" void f_80055D68() {}
