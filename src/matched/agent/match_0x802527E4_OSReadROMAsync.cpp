// 0x802527E4 __OSReadROMAsync (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stw 31,0x2c(1); addi 31,6,0; stw 30,0x28(1); addi 30,5,0; stw 29,0x24(1); addi 29,4,0; stw 28,0x20(1); addi 28,3,0; bl _s802527E4_0; lis 3,-32694; addi 3,3,-24704; stw 31,0x50(3); li 3,0; li 4,1; li 5,0; bl _s802527E4_1; cmpwi 3,0; bne 0f; li 3,0; b 2f; 0:; li 3,0; li 4,1; li 5,3; bl _s802527E4_2; cmpwi 3,0; bne 1f; li 3,0; bl _s802527E4_3; li 3,0; b 2f; 1:; rlwinm 0,30,6,0,25; stw 0,0x18(1); addi 4,1,24; li 3,0; li 5,4; li 6,1; li 7,0; bl _s802527E4_4; cntlzw 0,3; rlwinm 31,0,27,5,31; li 3,0; bl _s802527E4_5; cntlzw 0,3; lis 3,-32731; rlwinm 0,0,27,5,31; addi 7,3,10120; addi 4,28,0; addi 5,29,0; or 31,31,0; li 3,0; li 6,0; bl _s802527E4_6; cntlzw 0,3; rlwinm 0,0,27,5,31; or 31,31,0; cntlzw 0,31; rlwinm 3,0,27,5,31; 2:; lwz 0,0x34(1); lwz 31,0x2c(1); lwz 30,0x28(1); lwz 29,0x24(1); lwz 28,0x20(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s802527E4_0();
extern "C" void _s802527E4_1();
extern "C" void _s802527E4_2();
extern "C" void _s802527E4_3();
extern "C" void _s802527E4_4();
extern "C" void _s802527E4_5();
extern "C" void _s802527E4_6();
extern "C" void f_802527E4() {}
