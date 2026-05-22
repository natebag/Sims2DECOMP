// 0x8001EA9C ESimsCam::GetMode(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x3cc(3)"
extern "C" int f_8001EA9C() {}
