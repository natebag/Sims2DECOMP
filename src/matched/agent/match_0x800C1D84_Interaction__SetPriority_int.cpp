// 0x800C1D84 Interaction::SetPriority(int) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x28(3)"
extern "C" void f_800C1D84() {}
