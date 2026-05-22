// 0x80388F74 __GXWriteFifoIntEnable (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 5,-17720(13); rlwinm 0,4,0,24,31; lwz 4,0x8(5); rlwimi 4,3,2,29,29; stw 4,0x8(5); lwz 3,0x8(5); rlwimi 3,0,3,28,28; stw 3,0x8(5); lwz 0,0x8(5); lwz 3,-21996(13); sth 0,0x2(3)"
extern "C" void f_80388F74() {}
