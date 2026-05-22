// 0x80267C28 CheckMailBox (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 4,2; stw 0,0x4(1); lis 0,16384; li 5,1; stwu 1,-64(1); stw 31,0x3c(1); addi 3,1,36; stw 30,0x38(1); stw 29,0x34(1); stw 28,0x30(1); lis 28,-13312; addi 31,28,26624; lwz 6,0x6828(28); andi. 6,6,1029; ori 6,6,192; stwu 6,0x28(31); stw 0,0x24(1); bl _s80267C28_0; cntlzw 0,3; rlwinm 29,0,27,5,31; 0:; addi 30,28,26624; lwzu 0,0x34(30); rlwinm. 0,0,0,31,31; bne 0b; addi 3,1,40; li 4,4; li 5,0; bl _s80267C28_1; 1:; lwz 0,0x0(30); rlwinm. 0,0,0,31,31; bne 1b; lwz 0,0x0(31); andi. 0,0,1029; stw 0,0x0(31); lwz 0,0x28(1); rlwinm. 0,0,0,31,31; beq 4f; lwz 6,0x0(31); lis 0,24576; addi 3,1,32; andi. 6,6,1029; li 4,2; li 5,1; ori 6,6,192; stw 6,0x0(31); stw 0,0x20(1); bl _s80267C28_2; cntlzw 0,3; rlwinm 29,0,27,5,31; 2:; lwz 0,0x0(30); rlwinm. 0,0,0,31,31; bne 2b; addi 3,1,40; li 4,4; li 5,0; bl _s80267C28_3; 3:; lwz 0,0x0(30); rlwinm. 0,0,0,31,31; bne 3b; lwz 0,0x0(31); andi. 0,0,1029; stw 0,0x0(31); lwz 0,0x28(1); rlwinm 0,0,0,3,31; stw 0,0x28(1); lwz 4,0x28(1); rlwinm 3,4,0,3,7; addis 0,3,-7936; cmplwi 0,0; bne 4f; rlwinm 3,4,0,17,31; stw 4,-23048(13); li 0,1; stw 3,-23044(13); stb 0,-23036(13); 4:; lwz 0,0x44(1); lwz 31,0x3c(1); lwz 30,0x38(1); lwz 29,0x34(1); lwz 28,0x30(1); addi 1,1,64; mtspr 8,0"
extern "C" void _s80267C28_0();
extern "C" void _s80267C28_1();
extern "C" void _s80267C28_2();
extern "C" void _s80267C28_3();
extern "C" void f_80267C28() {}
