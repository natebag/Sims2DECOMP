// 0x80020CB0 ECheats::ReadCheatsFile(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-736(1); li 0,1; stw 0,0x104(3); addi 1,1,736"
extern "C" void f_80020CB0() {}
