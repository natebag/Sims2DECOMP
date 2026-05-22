// 0x802BC034 AptInteger::Destroy(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-26908(13); stw 0,0xc(3); stw 3,-26908(13)"
extern "C" void f_802BC034() {}
