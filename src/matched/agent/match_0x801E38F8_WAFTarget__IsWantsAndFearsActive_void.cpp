// 0x801E38F8 WAFTarget::IsWantsAndFearsActive(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x88(3)"
extern "C" int f_801E38F8() {}
