// 0x800C1D8C Interaction::HasID(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x38(3); li 3,1; cmplwi 0,0; bnelr; li 3,0"
extern "C" int f_800C1D8C() {}
