// 0x80264E68 __VIGetCurrentPosition (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 7,-13312; stw 0,0x4(1); addi 6,4,0; addi 9,7,8192; stwu 1,-8(1); addi 5,3,0; addi 4,7,8192; lhzu 0,0x2c(9); rlwinm 8,0,0,21,31; 0:; lhz 0,0x0(9); mr 7,8; lhz 3,0x2e(4); rlwinm 8,0,0,21,31; cmplw 7,8; rlwinm 0,3,0,21,31; bne 0b; mr 3,0; addi 4,8,0; bl _s80264E68_0; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80264E68_0();
extern "C" void f_80264E68() {}
