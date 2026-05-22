// 0x80256FD0 __EXIAttach (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); stw 30,0x20(1); stw 29,0x1c(1); stw 28,0x18(1); addi 28,3,0; addi 29,4,0; rlwinm 4,3,6,0,25; lis 3,-32694; addi 0,3,-22064; add 31,0,4; bl _s80256FD0_0; mr 30,3; lwz 0,0xc(31); rlwinm. 0,0,0,28,28; bne 0f; mr 3,28; bl _s80256FD0_1; cmpwi 3,0; bne 1f; 0:; mr 3,30; bl _s80256FD0_2; li 3,0; b 2f; 1:; mulli 0,28,20; lis 3,-13312; addi 3,3,26624; add 3,3,0; lwz 0,0x0(3); andi. 0,0,2037; ori 0,0,2; stw 0,0x0(3); stw 29,0x8(31); lis 3,16; mulli 0,28,3; srw 3,3,0; bl _s80256FD0_3; lwz 0,0xc(31); ori 0,0,8; stw 0,0xc(31); mr 3,30; bl _s80256FD0_4; li 3,1; 2:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); lwz 28,0x18(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80256FD0_0();
extern "C" void _s80256FD0_1();
extern "C" void _s80256FD0_2();
extern "C" void _s80256FD0_3();
extern "C" void _s80256FD0_4();
extern "C" void f_80256FD0() {}
