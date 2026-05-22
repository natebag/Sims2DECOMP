// 0x80337710 AudioDecode(THPReadBuffer (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 11,-32691; lwz 9,0x0(3); addi 28,11,14656; lwz 0,0x6c(28); addi 31,9,8; rlwinm 0,0,2,0,29; add 9,9,0; addi 29,9,8; bl _s80337710_0; lwz 0,0x6c(28); li 10,0; mr 30,3; cmplw 10,0; bge 2f; mr 11,28; addi 8,11,112; 0:; lbzx 0,8,10; cmpwi 0,1; bne 1f; lwz 0,0xec(11); li 5,0; lwz 4,0x0(31); lwz 3,0x0(30); mullw 4,4,0; add 4,29,4; bl _s80337710_1; lwz 0,0x0(30); stw 3,0x8(30); mr 3,30; stw 0,0x4(30); bl _s80337710_2; b 2f; 1:; lwz 9,0x0(31); addi 10,10,1; lwz 0,0x6c(11); addi 31,31,4; add 29,29,9; cmplw 10,0; blt 0b; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80337710_0();
extern "C" void _s80337710_1();
extern "C" void _s80337710_2();
extern "C" void f_80337710() {}
