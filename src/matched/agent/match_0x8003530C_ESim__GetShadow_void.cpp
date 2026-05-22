// 0x8003530C ESim::GetShadow(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x3e0(3)"
extern "C" int f_8003530C() {}
