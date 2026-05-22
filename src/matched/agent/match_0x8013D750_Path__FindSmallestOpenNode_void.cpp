// 0x8013D750 Path::FindSmallestOpenNode(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stmw 27,0xc(1); stw 0,0x2c(1); mr 30,3; li 28,0; lwz 9,0x3c(30); lis 3,-32696; addi 3,3,26792; addi 29,30,60; lwz 4,0x0(9); lis 27,-32696; bl _s8013D750_0; lwz 9,0x3c(30); lwz 0,0x4(29); addi 31,9,4; lfs f31,0x20(3); cmpw 31,0; beq 2f; 0:; lwz 4,0x0(31); addi 3,27,26792; bl _s8013D750_1; lfs f0,0x20(3); fcmpu 0,f0,f31; bge 1f; lwz 0,0x3c(30); fmr f31,f0; subf 0,0,31; srawi 28,0,2; 1:; lwz 0,0x4(29); addi 31,31,4; cmpw 31,0; bne 0b; 2:; lwz 11,0x3c(30); rlwinm 9,28,2,0,29; lwzx 3,11,9; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0xc(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s8013D750_0();
extern "C" void _s8013D750_1();
extern "C" void f_8013D750() {}
