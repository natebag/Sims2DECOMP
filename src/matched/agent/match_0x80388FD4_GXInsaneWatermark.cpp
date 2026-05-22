// 0x80388FD4 __GXInsaneWatermark (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-21956(13); lwz 3,0x10(4); addi 0,3,512; stw 0,0xc(4); lwz 0,0xc(4); lwz 3,-21996(13); sth 0,0x28(3); lwz 0,0xc(4); lwz 3,-21996(13); rlwinm 0,0,16,18,31; sth 0,0x2a(3)"
extern "C" void f_80388FD4() {}
