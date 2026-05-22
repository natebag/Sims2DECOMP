// 0x8038B9E4 GXGetPointSize (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 5,-17720(13); lwz 0,0x7c(5); rlwinm 0,0,24,24,31; stb 0,0x0(3); lwz 0,0x7c(5); rlwinm 0,0,13,29,31; stw 0,0x0(4)"
extern "C" void f_8038B9E4() {}
