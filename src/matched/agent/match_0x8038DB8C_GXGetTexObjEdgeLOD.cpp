// 0x8038DB8C GXGetTexObjEdgeLOD (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); rlwinm 0,0,24,31,31; cntlzw 0,0; rlwinm 3,0,27,24,31"
extern "C" int f_8038DB8C() {}
