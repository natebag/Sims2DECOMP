// 0x80267EC0 DBGReadStatus (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 4,2; stw 0,0x4(1); lis 0,16384; stwu 1,-56(1); stmw 27,0x24(1); lis 30,-13312; addi 27,3,0; addi 29,30,26624; addi 3,1,24; lwz 5,0x6828(30); andi. 5,5,1029; ori 5,5,192; stwu 5,0x28(29); li 5,1; stw 0,0x18(1); bl _s80267EC0_0; cntlzw 0,3; rlwinm 31,0,27,5,31; 0:; addi 28,30,26624; lwzu 0,0x34(28); rlwinm. 0,0,0,31,31; bne 0b; addi 3,27,0; li 4,4; li 5,0; bl _s80267EC0_1; cntlzw 0,3; rlwinm 0,0,27,5,31; or 3,31,0; 1:; lwz 0,0x0(28); rlwinm. 0,0,0,31,31; bne 1b; lwz 4,0x0(29); cntlzw 0,3; rlwinm 3,0,27,5,31; andi. 0,4,1029; stw 0,0x0(29); lmw 27,0x24(1); lwz 0,0x3c(1); addi 1,1,56; mtspr 8,0"
extern "C" void _s80267EC0_0();
extern "C" void _s80267EC0_1();
extern "C" void f_80267EC0() {}
