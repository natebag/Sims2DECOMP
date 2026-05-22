// 0x80392E6C __VMIsARAMPageDirty (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-21852(13); rlwinm 0,3,22,17,29; lwzx 0,4,0; rlwinm 3,0,1,31,31"
extern "C" int f_80392E6C() {}
