// 0x8024CCB8 ICSync (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="isync"
extern "C" int f_8024CCB8() {}
