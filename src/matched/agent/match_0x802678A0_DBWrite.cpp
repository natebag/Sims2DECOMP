// 0x802678A0 DBWrite (608 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-120(1); stmw 24,0x58(1); addi 26,3,0; addi 27,4,0; bl _s802678A0_0; addi 28,3,0; lis 25,-13312; lis 31,16384; 0:; lwz 0,0x6828(25); addi 30,25,26624; addi 3,1,80; andi. 0,0,1029; li 4,2; li 5,1; ori 0,0,192; stwu 0,0x28(30); stw 31,0x50(1); bl _s802678A0_1; cntlzw 0,3; rlwinm 24,0,27,5,31; 1:; addi 29,25,26624; lwzu 0,0x34(29); rlwinm. 0,0,0,31,31; bne 1b; addi 3,1,84; li 4,4; li 5,0; bl _s802678A0_2; 2:; lwz 0,0x0(29); rlwinm. 0,0,0,31,31; bne 2b; lwz 0,0x0(30); andi. 0,0,1029; stw 0,0x0(30); lwz 0,0x54(1); rlwinm. 0,0,0,30,30; bne 0b; lbz 3,-27616(13); addi 0,3,1; stb 0,-27616(13); lbz 0,-27616(13); rlwinm. 0,0,0,31,31; beq 3f; li 3,4096; b 4f; 3:; li 3,0; 4:; addi 0,27,3; oris 25,3,1; rlwinm 24,0,0,0,29; ori 25,25,49152; 5:; addi 3,25,0; addi 4,26,0; addi 5,24,0; bl _s802678A0_3; cmpwi 3,0; beq 5b; lis 31,16384; 6:; lwz 0,0x0(30); addi 3,1,76; li 4,2; andi. 0,0,1029; li 5,1; ori 0,0,192; stw 0,0x0(30); stw 31,0x4c(1); bl _s802678A0_4; cntlzw 0,3; rlwinm 26,0,27,5,31; 7:; lwz 0,0x0(29); rlwinm. 0,0,0,31,31; bne 7b; addi 3,1,84; li 4,4; li 5,0; bl _s802678A0_5; 8:; lwz 0,0x0(29); rlwinm. 0,0,0,31,31; bne 8b; lwz 0,0x0(30); andi. 0,0,1029; stw 0,0x0(30); lwz 0,0x54(1); rlwinm. 0,0,0,30,30; bne 6b; lbz 0,-27616(13); rlwinm 0,0,16,0,15; oris 0,0,7936; or 0,0,27; rlwinm 0,0,0,3,31; oris 24,0,49152; 9:; lwz 0,0x0(30); addi 3,1,68; li 4,4; andi. 0,0,1029; li 5,1; ori 0,0,192; stw 0,0x0(30); stw 24,0x44(1); bl _s802678A0_6; cntlzw 0,3; rlwinm 3,0,27,5,31; 10:; lwz 0,0x0(29); rlwinm. 0,0,0,31,31; bne 10b; lwz 0,0x0(30); andi. 0,0,1029; cmpwi 3,0; stw 0,0x0(30); bne 9b; lis 27,16384; 11:; lwz 0,0x0(30); addi 3,1,60; li 4,2; andi. 0,0,1029; li 5,1; ori 0,0,192; stw 0,0x0(30); stw 27,0x3c(1); bl _s802678A0_7; cntlzw 0,3; rlwinm 26,0,27,5,31; 12:; lwz 0,0x0(29); rlwinm. 0,0,0,31,31; bne 12b; addi 3,1,84; li 4,4; li 5,0; bl _s802678A0_8; cntlzw 0,3; rlwinm 0,0,27,5,31; or 3,26,0; 13:; lwz 0,0x0(29); rlwinm. 0,0,0,31,31; bne 13b; lwz 0,0x0(30); andi. 0,0,1029; cmpwi 3,0; stw 0,0x0(30); bne 11b; lwz 0,0x54(1); rlwinm. 0,0,0,30,30; bne 11b; mr 3,28; bl _s802678A0_9; lmw 24,0x58(1); li 3,0; lwz 0,0x7c(1); addi 1,1,120; mtspr 8,0"
extern "C" void _s802678A0_0();
extern "C" void _s802678A0_1();
extern "C" void _s802678A0_2();
extern "C" void _s802678A0_3();
extern "C" void _s802678A0_4();
extern "C" void _s802678A0_5();
extern "C" void _s802678A0_6();
extern "C" void _s802678A0_7();
extern "C" void _s802678A0_8();
extern "C" void _s802678A0_9();
extern "C" void f_802678A0() {}
