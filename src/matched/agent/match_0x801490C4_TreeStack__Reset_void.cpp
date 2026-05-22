// 0x801490C4 TreeStack::Reset(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x8(3); stw 0,0xc(3)"
extern "C" void f_801490C4() {}
