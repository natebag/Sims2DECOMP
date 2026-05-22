// 0x801BC998 INGTarget::RCPOnCancel(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,2; stw 0,0x458(3); li 3,1"
extern "C" void f_801BC998() {}
