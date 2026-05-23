// 0x800C1DA4 Interaction::GetID(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x38(3)"
extern "C" int f_800C1DA4() {}
