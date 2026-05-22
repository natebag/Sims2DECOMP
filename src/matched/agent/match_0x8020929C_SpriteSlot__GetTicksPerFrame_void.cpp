// 0x8020929C SpriteSlot::GetTicksPerFrame(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 0,0x4(11)"
extern "C" void f_8020929C() {}
