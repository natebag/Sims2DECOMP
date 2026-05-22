// 0x8003535C ESim::GetPlumbBobState(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x3ec(3)"
extern "C" int f_8003535C() {}
