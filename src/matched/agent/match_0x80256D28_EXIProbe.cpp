// 0x80256D28 __EXIProbe (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stmw 27,0x14(1); addi 28,3,0; rlwinm 4,3,6,0,25; lis 3,-32694; addi 0,3,-22064; add 31,0,4; cmpwi 28,2; bne 0f; li 3,1; b 7f; 0:; li 29,1; bl _s80256D28_0; addi 30,3,0; mulli 0,28,20; lis 3,-13312; addi 3,3,26624; add 3,3,0; lwz 5,0x0(3); lwz 0,0xc(31); rlwinm. 0,0,0,28,28; bne 4f; rlwinm. 0,5,0,20,20; beq 1f; lwz 0,0x0(3); andi. 0,0,2037; ori 0,0,2048; stw 0,0x0(3); li 4,0; stw 4,0x20(31); rlwinm 0,28,2,0,29; lis 3,-32768; addi 3,3,12480; stwx 4,3,0; 1:; rlwinm. 0,5,0,19,19; beq 3f; lis 31,-32768; lwz 0,0xf8(31); rlwinm 0,0,30,2,31; lis 3,4194; addi 3,3,19923; mulhwu 0,3,0; rlwinm 27,0,26,6,31; bl _s80256D28_1; li 5,0; addi 6,27,0; bl _s80256D28_2; li 5,0; li 6,100; bl _s80256D28_3; addi 4,4,1; rlwinm 0,28,2,0,29; addi 3,31,12480; add 3,3,0; lwz 0,0x0(3); cmpwi 0,0; bne 2f; stw 4,0x0(3); 2:; lwz 0,0x0(3); subf 0,0,4; cmpwi 0,3; bge 6f; li 29,0; b 6f; 3:; li 4,0; stw 4,0x20(31); rlwinm 0,28,2,0,29; lis 3,-32768; addi 3,3,12480; stwx 4,3,0; li 29,0; b 6f; 4:; rlwinm. 0,5,0,19,19; beq 5f; rlwinm. 0,5,0,20,20; beq 6f; 5:; li 4,0; stw 4,0x20(31); rlwinm 0,28,2,0,29; lis 3,-32768; addi 3,3,12480; stwx 4,3,0; li 29,0; 6:; mr 3,30; bl _s80256D28_4; mr 3,29; 7:; lwz 0,0x2c(1); lmw 27,0x14(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80256D28_0();
extern "C" void _s80256D28_1();
extern "C" void _s80256D28_2();
extern "C" void _s80256D28_3();
extern "C" void _s80256D28_4();
extern "C" void f_80256D28() {}
