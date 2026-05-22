// 0x8038DBA0 GXGetTexObjMaxAniso (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); rlwinm 3,0,13,30,31"
extern "C" int f_8038DBA0() {}
