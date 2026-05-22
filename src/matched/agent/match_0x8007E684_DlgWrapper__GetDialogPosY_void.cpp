// 0x8007E684 DlgWrapper::GetDialogPosY(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0xc0(3)"
extern "C" int f_8007E684() {}
