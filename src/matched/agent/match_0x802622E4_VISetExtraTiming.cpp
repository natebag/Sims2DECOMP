// 0x802622E4 __VISetExtraTiming (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-23196(13); stw 3,-23196(13); mr 3,0"
extern "C" void f_802622E4() {}
