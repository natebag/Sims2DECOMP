// 0x8038DAB8 GXGetTexObjMinFilt (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); addi 3,13,-25232; rlwinm 0,0,27,29,31; lbzx 3,3,0"
extern "C" int f_8038DAB8() {}
