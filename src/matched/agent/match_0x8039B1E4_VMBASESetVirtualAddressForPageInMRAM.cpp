// 0x8039B1E4 __VMBASESetVirtualAddressForPageInMRAM (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 5,-21532(13); rlwinm 0,3,2,0,29; stwx 4,5,0"
extern "C" void f_8039B1E4() {}
