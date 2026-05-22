// 0x8038BA74 GXGetCullMode (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-17720(13); lwz 4,0x204(4); rlwinm 0,4,18,30,30; srawi 0,0,1; rlwimi 0,4,19,30,30; stw 0,0x0(3)"
extern "C" void f_8038BA74() {}
