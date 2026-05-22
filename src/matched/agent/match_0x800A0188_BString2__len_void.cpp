// 0x800A0188 BString2::len(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); addi 3,3,4"
extern "C" int f_800A0188() {}
