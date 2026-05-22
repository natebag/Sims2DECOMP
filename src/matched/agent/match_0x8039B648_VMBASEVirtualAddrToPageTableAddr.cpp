// 0x8039B648 __VMBASEVirtualAddrToPageTableAddr (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-21536(13); rlwinm 0,3,26,16,25; rlwinm 3,3,13,26,28; or 0,4,0; or 3,3,0"
extern "C" int f_8039B648() {}
