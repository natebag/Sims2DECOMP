// 0x8038E154 GXGetTlutRegionAll (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); rlwinm 6,0,9,13,22; addis 0,6,8; stw 0,0x0(4); lwz 0,0x0(3); rlwinm 0,0,22,21,31; stw 0,0x0(5)"
extern "C" void f_8038E154() {}
