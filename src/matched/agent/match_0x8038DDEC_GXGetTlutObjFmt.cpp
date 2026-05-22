// 0x8038DDEC GXGetTlutObjFmt (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); rlwinm 3,0,22,30,31"
extern "C" int f_8038DDEC() {}
