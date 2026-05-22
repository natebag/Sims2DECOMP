// 0x8007F06C DlgWrapper::IsAptDrawable(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xb4(3)"
extern "C" int f_8007F06C() {}
