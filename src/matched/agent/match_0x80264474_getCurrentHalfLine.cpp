// 0x80264474 getCurrentHalfLine (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; addi 7,3,8192; lhzu 0,0x2c(7); addi 4,3,8192; rlwinm 5,0,0,21,31; 0:; lhz 0,0x0(7); mr 6,5; lhz 3,0x2e(4); rlwinm 5,0,0,21,31; cmplw 6,5; rlwinm 6,3,0,21,31; bne 0b; lwz 3,-23216(13); addi 5,5,-1; addi 4,6,-1; lhz 0,0x1a(3); rlwinm 3,5,1,0,30; divwu 0,4,0; add 3,3,0"
extern "C" int f_80264474() {}
