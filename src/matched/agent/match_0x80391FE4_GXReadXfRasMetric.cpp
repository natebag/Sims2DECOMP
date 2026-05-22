// 0x80391FE4 GXReadXfRasMetric (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 7,-21996(13); addi 10,7,66; lhz 8,0x42(7); addi 9,7,64; 0:; mr 0,8; lhz 7,0x0(9); lhz 8,0x0(10); cmplw 8,0; bne 0b; rlwinm 0,8,16,0,15; or 0,0,7; stw 0,0x0(5); lwz 5,-21996(13); addi 9,5,70; lhz 7,0x46(5); addi 8,5,68; 1:; mr 0,7; lhz 5,0x0(8); lhz 7,0x0(9); cmplw 7,0; bne 1b; rlwinm 0,7,16,0,15; or 0,0,5; stw 0,0x0(6); lwz 5,-21996(13); addi 8,5,74; lhz 6,0x4a(5); addi 7,5,72; 2:; mr 0,6; lhz 5,0x0(7); lhz 6,0x0(8); cmplw 6,0; bne 2b; rlwinm 0,6,16,0,15; or 0,0,5; stw 0,0x0(3); lwz 3,-21996(13); addi 7,3,78; lhz 5,0x4e(3); addi 6,3,76; 3:; mr 0,5; lhz 3,0x0(6); lhz 5,0x0(7); cmplw 5,0; bne 3b; rlwinm 0,5,16,0,15; or 0,0,3; stw 0,0x0(4)"
extern "C" void f_80391FE4() {}
