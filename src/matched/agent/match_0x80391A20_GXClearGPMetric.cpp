// 0x80391A20 GXClearGPMetric (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-21996(13); li 0,4; sth 0,0x4(3)"
extern "C" void f_80391A20() {}
