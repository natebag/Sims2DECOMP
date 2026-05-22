// 0x802D418C EString2::SetToNull(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 0,13,-26852; stw 0,0x0(3)"
extern "C" void f_802D418C() {}
