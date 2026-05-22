// 0x8009BAA0 BitMatrix64::BitMatrix64(BitMatrix64 (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; mr 28,4; mr 31,29; li 30,63; 0:; mr 3,31; bl _s8009BAA0_0; addi 31,31,8; cmpwi 30,0; addi 30,30,-1; bne 0b; mr 4,28; mr 9,29; li 11,504; 1:; lwz 0,0x0(4); addic. 11,11,-24; stw 0,0x0(9); lwz 0,0x4(4); stw 0,0x4(9); lwz 0,0x8(4); stw 0,0x8(9); lwz 0,0xc(4); stw 0,0xc(9); lwz 0,0x10(4); stw 0,0x10(9); lwz 0,0x14(4); addi 4,4,24; stw 0,0x14(9); addi 9,9,24; bne 1b; lwz 0,0x0(4); mr 3,29; stw 0,0x0(9); lwz 0,0x4(4); stw 0,0x4(9); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8009BAA0_0();
extern "C" void f_8009BAA0() {}
