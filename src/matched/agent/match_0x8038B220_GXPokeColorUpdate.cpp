// 0x8038B220 GXPokeColorUpdate (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-21992(13); rlwinm 0,3,0,24,31; lhz 3,0x2(4); rlwimi 3,0,3,28,28; sth 3,0x2(4)"
extern "C" void f_8038B220() {}
