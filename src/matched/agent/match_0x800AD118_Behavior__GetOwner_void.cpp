// 0x800AD118 Behavior::GetOwner(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x4(3)"
extern "C" int f_800AD118() {}
