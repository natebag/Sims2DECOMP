// 0x80238298 ERLevel::IsInUse(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addis 3,3,3; lwz 3,-23888(3)"
extern "C" int f_80238298() {}
