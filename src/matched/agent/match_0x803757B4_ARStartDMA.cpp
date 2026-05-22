// 0x803757B4 ARStartDMA (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); addi 31,6,0; stw 30,0x20(1); addi 30,5,0; stw 29,0x1c(1); addi 29,3,0; stw 28,0x18(1); addi 28,4,0; bl _s803757B4_0; lis 6,-13312; lhz 0,0x5020(6); addi 8,6,20480; addi 9,6,20480; rlwinm 4,0,0,0,21; rlwinm 0,28,16,16,31; or 0,4,0; sth 0,0x5020(6); rlwinm 0,28,0,16,31; addi 4,6,20480; lhz 5,0x5022(6); rlwinm 5,5,0,27,15; or 0,5,0; sth 0,0x5022(6); addi 5,6,20480; rlwinm 0,30,16,16,31; lhz 6,0x5024(6); rlwinm 6,6,0,0,21; or 0,6,0; sth 0,0x24(8); rlwinm 0,30,0,16,31; lhz 6,0x26(9); rlwinm 6,6,0,27,15; or 0,6,0; sth 0,0x26(9); rlwinm 6,31,16,16,31; rlwinm 0,31,0,16,31; lhz 7,0x28(4); rlwinm 7,7,0,17,15; rlwimi 7,29,15,0,16; sth 7,0x28(4); lhz 7,0x28(4); rlwinm 7,7,0,0,21; or 6,7,6; sth 6,0x28(4); lhz 4,0x2a(5); rlwinm 4,4,0,27,15; or 0,4,0; sth 0,0x2a(5); bl _s803757B4_1; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); lwz 28,0x18(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s803757B4_0();
extern "C" void _s803757B4_1();
extern "C" void f_803757B4() {}
