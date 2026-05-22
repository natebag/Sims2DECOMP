// 0x8015A0E0 QuickDataBehaviorConstants::AddRef(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; lwz 3,0x1c(9); addi 3,3,1; stw 3,0x1c(9)"
extern "C" void f_8015A0E0() {}
