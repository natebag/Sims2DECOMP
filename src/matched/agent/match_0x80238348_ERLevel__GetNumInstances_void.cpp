// 0x80238348 ERLevel::GetNumInstances(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addis 3,3,3; lwz 3,-15688(3)"
extern "C" int f_80238348() {}
