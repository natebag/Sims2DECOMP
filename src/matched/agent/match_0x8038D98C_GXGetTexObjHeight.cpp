// 0x8038D98C GXGetTexObjHeight (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x8(3); rlwinm 3,0,22,22,31; addi 3,3,1"
extern "C" int f_8038D98C() {}
