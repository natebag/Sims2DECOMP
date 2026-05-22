// 0x8007E5E0 DlgWrapper::GetFont(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xa8(3)"
extern "C" int f_8007E5E0() {}
