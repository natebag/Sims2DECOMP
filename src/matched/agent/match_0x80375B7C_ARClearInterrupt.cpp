// 0x80375B7C __ARClearInterrupt (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; addi 3,3,20480; lhz 4,0xa(3); li 0,-137; and 0,4,0; ori 0,0,32; sth 0,0xa(3)"
extern "C" void f_80375B7C() {}
