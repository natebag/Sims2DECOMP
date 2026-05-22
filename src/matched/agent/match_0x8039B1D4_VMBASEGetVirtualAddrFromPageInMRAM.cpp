// 0x8039B1D4 VMBASEGetVirtualAddrFromPageInMRAM (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-21532(13); rlwinm 0,3,2,0,29; lwzx 3,4,0"
extern "C" int f_8039B1D4() {}
