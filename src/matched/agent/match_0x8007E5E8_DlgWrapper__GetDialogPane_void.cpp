// 0x8007E5E8 DlgWrapper::GetDialogPane(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xac(3)"
extern "C" int f_8007E5E8() {}
