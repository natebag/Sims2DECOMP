// 0x800C1C7C Interaction::GetPerson(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x8(3)"
extern "C" int f_800C1C7C() {}
