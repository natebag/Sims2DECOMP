// 0x80392E54 __VMSetARAMPageAsDirty (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-21852(13); rlwinm 3,3,22,17,29; lwzx 0,4,3; oris 0,0,32768; stwx 0,4,3"
extern "C" void f_80392E54() {}
