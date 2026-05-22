// 0x8038D9BC GXGetTexObjMipMap (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,0x1f(3); rlwinm 3,0,0,31,31; addi 0,3,-1; cntlzw 0,0; rlwinm 3,0,27,24,31"
extern "C" int f_8038D9BC() {}
