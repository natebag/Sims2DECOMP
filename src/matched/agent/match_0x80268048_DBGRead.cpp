// 0x80268048 DBGRead (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); rlwinm 0,3,8,7,21; oris 0,0,8192; stwu 1,-64(1); stmw 26,0x28(1); lis 29,-13312; addi 30,5,0; addi 26,4,0; addi 31,29,26624; addi 3,1,36; li 4,4; li 5,1; lwz 6,0x6828(29); andi. 6,6,1029; ori 6,6,192; stwu 6,0x28(31); stw 0,0x24(1); bl _s80268048_0; cntlzw 0,3; rlwinm 0,0,27,5,31; mr 27,0; 0:; addi 28,29,26624; lwzu 0,0x34(28); rlwinm. 0,0,0,31,31; bne 0b; b 3f; 1:; addi 3,1,32; li 4,4; li 5,0; bl _s80268048_1; cntlzw 0,3; rlwinm 0,0,27,5,31; or 27,27,0; 2:; lwz 0,0x0(28); rlwinm. 0,0,0,31,31; bne 2b; lwz 0,0x20(1); addic. 30,30,-4; stw 0,0x0(26); addi 26,26,4; bge 3f; li 30,0; 3:; cmpwi 30,0; bne 1b; lwz 4,0x0(31); cntlzw 0,27; rlwinm 3,0,27,5,31; andi. 0,4,1029; stw 0,0x0(31); lmw 26,0x28(1); lwz 0,0x44(1); addi 1,1,64; mtspr 8,0"
extern "C" void _s80268048_0();
extern "C" void _s80268048_1();
extern "C" void f_80268048() {}
