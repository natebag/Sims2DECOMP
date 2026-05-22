// 0x80388FA4 __GXWriteFifoIntReset (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 5,-17720(13); rlwinm 0,4,0,24,31; lwz 4,0x10(5); rlwimi 4,3,0,31,31; stw 4,0x10(5); lwz 3,0x10(5); rlwimi 3,0,1,30,30; stw 3,0x10(5); lwz 0,0x10(5); lwz 3,-21996(13); sth 0,0x4(3)"
extern "C" void f_80388FA4() {}
