// 0x802644C4 getCurrentFieldEvenOdd (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; addi 7,3,8192; lhzu 0,0x2c(7); addi 4,3,8192; rlwinm 5,0,0,21,31; 0:; lhz 0,0x0(7); mr 6,5; lhz 3,0x2e(4); rlwinm 5,0,0,21,31; cmplw 6,5; rlwinm 3,3,0,21,31; bne 0b; lwz 6,-23216(13); addi 0,5,-1; addi 4,3,-1; lhz 3,0x1a(6); rlwinm 5,0,1,0,30; lhz 0,0x18(6); divwu 3,4,3; add 3,5,3; cmplw 3,0; bge 1f; li 3,1; blr; 1:; li 3,0"
extern "C" int f_802644C4() {}
