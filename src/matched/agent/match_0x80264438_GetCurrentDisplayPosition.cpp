// 0x80264438 GetCurrentDisplayPosition (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 5,-13312; addi 7,5,8192; lhzu 0,0x2c(7); addi 6,5,8192; rlwinm 9,0,0,21,31; 0:; lhz 0,0x0(7); mr 8,9; lhz 5,0x2e(6); rlwinm 9,0,0,21,31; cmplw 8,9; rlwinm 0,5,0,21,31; bne 0b; stw 0,0x0(3); stw 9,0x0(4)"
extern "C" void f_80264438() {}
