// 0x802D293C EString::SetToNull(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 0,13,-26856; stw 0,0x0(3)"
extern "C" void f_802D293C() {}
