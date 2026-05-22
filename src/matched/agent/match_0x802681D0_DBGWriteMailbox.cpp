// 0x802681D0 DBGWriteMailbox (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 4,4; stw 0,0x4(1); rlwinm 0,3,0,3,31; oris 0,0,49152; stwu 1,-32(1); stw 31,0x1c(1); lis 31,-13312; addi 3,1,20; stw 30,0x18(1); addi 30,31,26624; lwz 5,0x6828(31); andi. 5,5,1029; ori 5,5,192; stwu 5,0x28(30); li 5,1; stw 0,0x14(1); bl _s802681D0_0; cntlzw 0,3; rlwinm 4,0,27,5,31; addi 3,31,26624; 0:; lwz 0,0x34(3); rlwinm. 0,0,0,31,31; bne 0b; lwz 5,0x0(30); cntlzw 0,4; rlwinm 3,0,27,5,31; andi. 0,5,1029; stw 0,0x0(30); lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s802681D0_0();
extern "C" void f_802681D0() {}
