// 0x80307CB0 EVibrate::Disable(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x0(3)"
extern "C" void f_80307CB0() {}
