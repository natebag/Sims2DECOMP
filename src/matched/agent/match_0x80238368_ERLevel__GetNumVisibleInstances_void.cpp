// 0x80238368 ERLevel::GetNumVisibleInstances(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addis 3,3,3; lwz 3,-7476(3)"
extern "C" int f_80238368() {}
