// 0x80379208 AXSetMode (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-22208(13); cmplw 0,3; beqlr; stw 3,-22208(13)"
extern "C" void f_80379208() {}
