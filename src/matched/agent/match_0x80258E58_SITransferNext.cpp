// 0x80258E58 SITransferNext (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32694; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,4,-21872; stw 30,0x18(1); stw 29,0x14(1); li 29,0; stw 28,0x10(1); addi 28,3,0; 0:; addi 28,28,1; srawi 0,28,2; addze 0,0; rlwinm 0,0,2,0,29; subfc 0,0,28; mr 28,0; rlwinm 0,0,5,0,26; add 30,31,0; lwz 0,0x0(30); cmpwi 0,-1; beq 1f; bl _s80258E58_0; lwz 0,0x18(30); xoris 5,3,32768; lwz 6,0x1c(30); xoris 3,0,32768; subfc 0,6,4; subfe 3,3,5; subfe 3,5,5; neg. 3,3; bne 1f; lwz 3,0x0(30); lwz 4,0x4(30); lwz 5,0x8(30); lwz 6,0xc(30); lwz 7,0x10(30); lwz 8,0x14(30); bl _s80258E58_1; cmpwi 3,0; beq 2f; mulli 4,28,40; lis 3,-32694; addi 0,3,-21744; add 3,0,4; bl _s80258E58_2; li 0,-1; stw 0,0x0(30); b 2f; 1:; addi 29,29,1; cmpwi 29,4; blt 0b; 2:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80258E58_0();
extern "C" void _s80258E58_1();
extern "C" void _s80258E58_2();
extern "C" void f_80258E58() {}
