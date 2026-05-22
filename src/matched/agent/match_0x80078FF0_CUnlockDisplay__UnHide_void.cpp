// 0x80078FF0 CUnlockDisplay::UnHide(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x458(3)"
extern "C" void f_80078FF0() {}
