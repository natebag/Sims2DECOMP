// 0x8038D970 GXGetTexObjData (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xc(3); rlwinm 3,0,5,6,26"
extern "C" int f_8038D970() {}
