// 0x8007E770 DlgWrapper::GetDialogWidth(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0xc4(3)"
extern "C" int f_8007E770() {}
