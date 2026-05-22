// 0x80238220 ERLevel::GetSunAmbient(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addis 3,3,3; addi 3,3,-7256"
extern "C" int f_80238220() {}
