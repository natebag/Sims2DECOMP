// 0x8018AAE8 LoadGameTarget::GetResult(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x10c(3)"
extern "C" int f_8018AAE8() {}
