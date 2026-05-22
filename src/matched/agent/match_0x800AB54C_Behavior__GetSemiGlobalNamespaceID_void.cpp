// 0x800AB54C Behavior::GetSemiGlobalNamespaceID(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); lwz 3,0x8(9)"
extern "C" int f_800AB54C() {}
