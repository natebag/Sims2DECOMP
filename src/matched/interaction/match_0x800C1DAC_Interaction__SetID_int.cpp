// 0x800C1DAC Interaction::SetID(int) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x38(3)"
extern "C" void f_800C1DAC() {}
