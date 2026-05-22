// 0x800C1FF8 Interaction::SetFlags(int) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x3c(3)"
extern "C" void f_800C1FF8() {}
