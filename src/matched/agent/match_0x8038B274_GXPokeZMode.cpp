// 0x8038B274 GXPokeZMode (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,3,0,24,31; lwz 3,-21992(13); li 6,0; rlwimi 6,0,0,31,31; rlwimi 6,4,1,28,30; rlwimi 6,5,4,27,27; sth 6,0x0(3)"
extern "C" void f_8038B274() {}
