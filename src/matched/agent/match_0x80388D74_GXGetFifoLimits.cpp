// 0x80388D74 GXGetFifoLimits (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xc(3); stw 0,0x0(4); lwz 0,0x10(3); stw 0,0x0(5)"
extern "C" void f_80388D74() {}
