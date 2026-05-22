// 0x80388F40 __GXFifoLink (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm. 0,3,0,24,31; beq 0f; li 4,1; b 1f; 0:; li 4,0; 1:; lwz 3,-17720(13); lwz 0,0x8(3); rlwimi 0,4,4,27,27; stw 0,0x8(3); lwz 0,0x8(3); lwz 3,-21996(13); sth 0,0x2(3)"
extern "C" void f_80388F40() {}
