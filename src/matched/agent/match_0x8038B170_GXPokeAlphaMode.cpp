// 0x8038B170 GXPokeAlphaMode (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 5,-21992(13); rlwinm 0,4,0,24,31; rlwimi 0,3,8,0,23; sth 0,0x6(5)"
extern "C" void f_8038B170() {}
