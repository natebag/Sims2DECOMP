// 0x803810C8 __CARDUpdateDir (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); stw 30,0x20(1); stw 29,0x1c(1); addi 29,4,0; stw 28,0x18(1); addi 28,3,0; mulli 5,28,272; lis 3,-32688; addi 0,3,-24000; add 30,0,5; lwz 0,0x0(30); cmpwi 0,0; bne 0f; li 3,-3; b 1f; 0:; lwz 31,0x84(30); li 4,8188; lha 5,0x1ffa(31); addi 6,31,8128; addi 3,31,0; addi 0,5,1; sth 0,0x1ffa(31); addi 5,6,60; addi 6,6,62; bl _s803810C8_0; addi 3,31,0; li 4,8192; bl _s803810C8_1; stw 29,0xd8(30); lis 3,-32712; addi 5,3,4096; lwz 0,0x80(30); mr 3,28; lwz 4,0xc(30); subf 0,0,31; rlwinm 0,0,19,13,31; mullw 4,4,0; bl _s803810C8_2; 1:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); lwz 28,0x18(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s803810C8_0();
extern "C" void _s803810C8_1();
extern "C" void _s803810C8_2();
extern "C" void f_803810C8() {}
