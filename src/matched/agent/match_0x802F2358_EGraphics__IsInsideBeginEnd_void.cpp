// 0x802F2358 EGraphics::IsInsideBeginEnd(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x4(3)"
extern "C" int f_802F2358() {}
