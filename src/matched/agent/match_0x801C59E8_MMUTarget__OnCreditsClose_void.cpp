// 0x801C59E8 MMUTarget::OnCreditsClose(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 0,0xfc(3)"
extern "C" void f_801C59E8() {}
