// 0x80335054 TexGet(TEXPalette (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x8(3); rlwinm 4,4,3,0,28; add 3,3,4"
extern "C" int f_80335054() {}
