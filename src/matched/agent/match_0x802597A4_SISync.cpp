// 0x802597A4 SISync (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-13312; stw 0,0x4(1); addi 3,3,25600; stwu 1,-32(1); stmw 26,0x8(1); 0:; lwz 0,0x34(3); rlwinm. 0,0,0,31,31; bne 0b; bl _s802597A4_0; mr 31,3; bl _s802597A4_1; lis 4,-32694; addi 30,3,0; addi 29,4,-21872; li 27,4; li 28,0; 1:; addi 27,27,1; srawi 0,27,2; addze 0,0; rlwinm 0,0,2,0,29; subfc 0,0,27; mr 27,0; rlwinm 0,0,5,0,26; add 26,29,0; lwz 0,0x0(26); cmpwi 0,-1; beq 2f; bl _s802597A4_2; lwz 0,0x18(26); xoris 5,3,32768; lwz 6,0x1c(26); xoris 3,0,32768; subfc 0,6,4; subfe 3,3,5; subfe 3,5,5; neg. 3,3; bne 2f; lwz 3,0x0(26); lwz 4,0x4(26); lwz 5,0x8(26); lwz 6,0xc(26); lwz 7,0x10(26); lwz 8,0x14(26); bl _s802597A4_3; cmpwi 3,0; beq 3f; mulli 4,27,40; lis 3,-32694; addi 0,3,-21744; add 3,0,4; bl _s802597A4_4; li 0,-1; stw 0,0x0(26); b 3f; 2:; addi 28,28,1; cmpwi 28,4; blt 1b; 3:; mr 3,31; bl _s802597A4_5; mr 3,30; lmw 26,0x8(1); lwz 0,0x24(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s802597A4_0();
extern "C" void _s802597A4_1();
extern "C" void _s802597A4_2();
extern "C" void _s802597A4_3();
extern "C" void _s802597A4_4();
extern "C" void _s802597A4_5();
extern "C" void f_802597A4() {}
