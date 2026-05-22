// 0x80035340 ESim::SetVanityDraw(bool, (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 5,0x3d4(3); stw 4,0x3dc(3)"
extern "C" void f_80035340() {}
