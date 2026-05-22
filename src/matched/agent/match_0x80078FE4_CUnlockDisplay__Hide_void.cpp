// 0x80078FE4 CUnlockDisplay::Hide(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 0,0x458(3)"
extern "C" void f_80078FE4() {}
