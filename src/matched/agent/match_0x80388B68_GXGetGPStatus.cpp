// 0x80388B68 GXGetGPStatus (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,-21996(13); lwz 8,-17720(13); lhz 0,0x0(9); stw 0,0xc(8); lwz 0,0xc(8); rlwinm 0,0,0,31,31; stb 0,0x0(3); lwz 0,0xc(8); rlwinm 0,0,31,31,31; stb 0,0x0(4); lwz 0,0xc(8); rlwinm 0,0,30,31,31; stb 0,0x0(5); lwz 0,0xc(8); rlwinm 0,0,29,31,31; stb 0,0x0(6); lwz 0,0xc(8); rlwinm 0,0,28,31,31; stb 0,0x0(7)"
extern "C" void f_80388B68() {}
