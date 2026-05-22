// 0x80238214 ERLevel::GetSun(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addis 3,3,3; addi 3,3,-7440"
extern "C" int f_80238214() {}
