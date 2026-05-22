// 0x80261EC8 VISetRegs (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32694; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,3,-16744; stw 30,0x18(1); stw 29,0x14(1); stw 28,0x10(1); lwz 0,-23232(13); cmplwi 0,1; bne 0f; bl _s80261EC8_0; cmplwi 3,0; beq 5f; 0:; lis 3,-13312; addi 30,3,8192; b 4f; 1:; lwz 3,-23224(13); li 5,32; lwz 28,-23220(13); addi 4,28,0; bl _s80261EC8_1; cntlzw 4,4; cmpwi 4,32; li 0,-1; and 0,28,0; bge 2f; b 3f; 2:; cntlzw 3,0; addi 4,3,32; 3:; rlwinm 6,4,1,0,30; add 3,31,6; lhz 0,0x78(3); subfic 5,4,63; li 3,0; sthx 0,30,6; li 4,1; bl _s80261EC8_2; lwz 0,-23224(13); not 5,3; not 4,4; lwz 3,-23220(13); and 0,0,5; and 3,3,4; stw 3,-23220(13); stw 0,-23224(13); 4:; lwz 0,-23224(13); li 4,0; lwz 3,-23220(13); xor 0,0,4; xor 3,3,4; or. 0,3,0; bne 1b; stw 4,-23232(13); li 3,1; lwz 0,-23208(13); lwz 4,0x144(31); stw 4,-23216(13); lwz 4,0x118(31); stw 4,-23212(13); stw 0,-23204(13); b 6f; 5:; li 3,0; 6:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80261EC8_0();
extern "C" void _s80261EC8_1();
extern "C" void _s80261EC8_2();
extern "C" void f_80261EC8() {}
