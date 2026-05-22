// 0x80380E7C __CARDUpdateFatBlock (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); stw 30,0x20(1); addi 30,5,0; stw 29,0x1c(1); addi 29,4,0; addi 5,29,0; stw 28,0x18(1); addi 28,3,0; addi 6,29,2; lhz 3,0x4(4); mulli 4,28,272; addi 0,3,1; lis 3,-32688; sth 0,0x4(29); addi 0,3,-24000; add 31,0,4; addi 3,29,4; li 4,8188; bl _s80380E7C_0; addi 3,29,0; li 4,8192; bl _s80380E7C_1; stw 30,0xd8(31); lis 3,-32712; addi 5,3,3072; lwz 0,0x80(31); mr 3,28; lwz 4,0xc(31); subf 0,0,29; rlwinm 0,0,19,13,31; mullw 4,4,0; bl _s80380E7C_2; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); lwz 28,0x18(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80380E7C_0();
extern "C" void _s80380E7C_1();
extern "C" void _s80380E7C_2();
extern "C" void f_80380E7C() {}
