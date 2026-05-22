// 0x80267374 AIGetStreamVolRight (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; lwz 0,0x6c04(3); rlwinm 3,0,24,24,31"
extern "C" int f_80267374() {}
