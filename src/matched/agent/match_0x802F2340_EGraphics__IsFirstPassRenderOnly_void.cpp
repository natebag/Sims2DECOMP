// 0x802F2340 EGraphics::IsFirstPassRenderOnly(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x31c(3)"
extern "C" int f_802F2340() {}
