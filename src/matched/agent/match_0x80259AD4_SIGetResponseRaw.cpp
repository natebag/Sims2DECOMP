// 0x80259AD4 SIGetResponseRaw (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32694; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); addi 31,4,-21872; stw 30,0x20(1); addi 30,3,0; stw 29,0x1c(1); bl _s80259AD4_0; lis 4,-13312; subfic 0,30,3; lwz 29,0x6438(4); rlwinm 0,0,3,0,28; srw 29,29,0; rlwinm. 0,29,0,28,28; beq 0f; lis 4,-32700; rlwinm 5,30,2,0,29; addi 0,4,-15952; add 4,0,5; lwz 0,0x0(4); rlwinm. 0,0,0,24,24; bne 0f; li 0,8; stw 0,0x0(4); 0:; bl _s80259AD4_1; rlwinm. 0,29,0,26,26; beq 1f; mulli 4,30,12; lis 3,-13312; addi 0,3,25600; add 3,0,4; rlwinm 4,30,3,0,28; lwz 0,0x4(3); add 6,31,4; stw 0,0x1c0(6); rlwinm 0,30,2,0,29; add 4,31,0; lwz 5,0x8(3); li 0,1; li 3,1; stw 5,0x1c4(6); stw 0,0x1b0(4); b 2f; 1:; li 3,0; 2:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80259AD4_0();
extern "C" void _s80259AD4_1();
extern "C" void f_80259AD4() {}
