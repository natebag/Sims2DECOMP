// 0x8024B040 PPCSetFpIEEEMode (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0xFFA0008C"
extern "C" float f_8024B040() {}
