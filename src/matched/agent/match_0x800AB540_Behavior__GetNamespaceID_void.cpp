// 0x800AB540 Behavior::GetNamespaceID(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); lwz 3,0x4(9)"
extern "C" int f_800AB540() {}
