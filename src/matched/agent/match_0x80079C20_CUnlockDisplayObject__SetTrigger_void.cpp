// 0x80079C20 CUnlockDisplayObject::SetTrigger(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 0,0x70(3)"
extern "C" void f_80079C20() {}
