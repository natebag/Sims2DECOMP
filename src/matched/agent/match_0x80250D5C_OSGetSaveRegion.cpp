// 0x80250D5C OSGetSaveRegion (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-23640(13); stw 0,0x0(3); lwz 0,-23636(13); stw 0,0x0(4)"
extern "C" void f_80250D5C() {}
