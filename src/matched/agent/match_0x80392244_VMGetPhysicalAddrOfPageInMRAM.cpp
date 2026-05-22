// 0x80392244 __VMGetPhysicalAddrOfPageInMRAM (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-21892(13); rlwinm 0,3,12,0,19; add 3,4,0"
extern "C" int f_80392244() {}
