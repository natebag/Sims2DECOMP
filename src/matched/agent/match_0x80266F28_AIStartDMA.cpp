// 0x80266F28 AIStartDMA (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; addi 3,3,20480; lhz 0,0x36(3); ori 0,0,32768; sth 0,0x36(3)"
extern "C" void f_80266F28() {}
