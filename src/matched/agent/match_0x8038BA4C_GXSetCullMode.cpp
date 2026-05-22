// 0x8038BA4C GXSetCullMode (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-17720(13); rlwinm 5,3,31,31,31; rlwimi 5,3,1,30,30; lwz 0,0x204(4); rlwimi 0,5,14,16,17; stw 0,0x204(4); lwz 0,0x5ac(4); ori 0,0,4; stw 0,0x5ac(4)"
extern "C" void f_8038BA4C() {}
