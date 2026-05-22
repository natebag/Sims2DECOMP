// 0x8039B198 __VMBASEClearPageFromTLB (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,3,0,14,19; .long 0x7C00046C; .long 0x7C000264"
extern "C" int f_8039B198() {}
