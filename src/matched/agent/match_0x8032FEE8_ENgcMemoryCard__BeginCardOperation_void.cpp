// 0x8032FEE8 ENgcMemoryCard::BeginCardOperation(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); addi 9,9,1; stw 9,0x4(3)"
extern "C" void f_8032FEE8() {}
