// 0x802513F8 OSSetBootDol (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-23624(13); stw 3,-23624(13); mr 3,0"
extern "C" void f_802513F8() {}
