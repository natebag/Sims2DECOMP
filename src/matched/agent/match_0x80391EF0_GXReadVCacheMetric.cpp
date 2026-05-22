// 0x80391EF0 GXReadVCacheMetric (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 6,-21996(13); addi 9,6,82; lhz 7,0x52(6); addi 8,6,80; 0:; mr 0,7; lhz 6,0x0(8); lhz 7,0x0(9); cmplw 7,0; bne 0b; rlwinm 0,7,16,0,15; or 0,0,6; stw 0,0x0(3); lwz 3,-21996(13); addi 8,3,86; lhz 6,0x56(3); addi 7,3,84; 1:; mr 0,6; lhz 3,0x0(7); lhz 6,0x0(8); cmplw 6,0; bne 1b; rlwinm 0,6,16,0,15; or 0,0,3; stw 0,0x0(4); lwz 3,-21996(13); addi 7,3,90; lhz 4,0x5a(3); addi 6,3,88; 2:; mr 0,4; lhz 3,0x0(6); lhz 4,0x0(7); cmplw 4,0; bne 2b; rlwinm 0,4,16,0,15; or 0,0,3; stw 0,0x0(5)"
extern "C" void f_80391EF0() {}
