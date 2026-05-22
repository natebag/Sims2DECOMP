// 0x80380DE0 __CARDFreeBlock (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; mulli 7,3,272; stw 0,0x4(1); lis 6,-32688; stwu 1,-8(1); addi 0,6,-24000; add 9,0,7; lwz 0,0x0(9); cmpwi 0,0; bne 0f; li 3,-3; b 5f; 0:; lwz 8,0x88(9); li 7,0; b 4f; 1:; rlwinm 4,4,0,16,31; cmplwi 4,5; blt 2f; lhz 0,0x10(9); cmplw 4,0; blt 3f; 2:; li 3,-6; b 5f; 3:; rlwinm 0,4,1,0,30; add 6,8,0; lhz 4,0x0(6); sth 7,0x0(6); lhz 6,0x6(8); addi 0,6,1; sth 0,0x6(8); 4:; rlwinm 0,4,0,16,31; cmplwi 0,65535; bne 1b; mr 4,8; bl _s80380DE0_0; 5:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80380DE0_0();
extern "C" void f_80380DE0() {}
