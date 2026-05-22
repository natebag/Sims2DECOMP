// 0x802BB8C4 AptBoolean::ForceDelete(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-26916(13); stw 0,0xc(3); stw 3,-26916(13)"
extern "C" void f_802BB8C4() {}
