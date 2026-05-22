// 0x802670FC AIGetStreamPlayState (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; lwz 0,0x6c00(3); rlwinm 3,0,0,31,31"
extern "C" int f_802670FC() {}
