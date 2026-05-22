// 0x80266FF0 AIResetStreamSampleCount (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; lwz 0,0x6c00(3); rlwinm 0,0,0,27,25; ori 0,0,32; stw 0,0x6c00(3)"
extern "C" void f_80266FF0() {}
