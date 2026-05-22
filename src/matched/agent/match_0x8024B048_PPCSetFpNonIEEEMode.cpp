// 0x8024B048 PPCSetFpNonIEEEMode (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0xFFA0004C"
extern "C" float f_8024B048() {}
