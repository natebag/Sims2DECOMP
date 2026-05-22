// 0x80250D50 OSSetSaveRegion (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 3,-23640(13); stw 4,-23636(13)"
extern "C" void f_80250D50() {}
