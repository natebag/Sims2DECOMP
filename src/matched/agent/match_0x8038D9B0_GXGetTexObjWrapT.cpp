// 0x8038D9B0 GXGetTexObjWrapT (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); rlwinm 3,0,30,30,31"
extern "C" int f_8038D9B0() {}
