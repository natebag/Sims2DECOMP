// 0x8038B9A4 GXSetPointSize (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 7,-17720(13); rlwinm 0,3,0,24,31; li 3,97; lwz 6,0x7c(7); rlwimi 6,0,8,16,23; lis 5,-13311; stw 6,0x7c(7); li 0,0; lwz 6,0x7c(7); rlwimi 6,4,19,10,12; stw 6,0x7c(7); stb 3,-32768(5); lwz 3,0x7c(7); stw 3,-32768(5); sth 0,0x2(7)"
extern "C" void f_8038B9A4() {}
