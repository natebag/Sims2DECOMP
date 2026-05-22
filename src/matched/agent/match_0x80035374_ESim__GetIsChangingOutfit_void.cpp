// 0x80035374 ESim::GetIsChangingOutfit(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x3d8(3)"
extern "C" int f_80035374() {}
