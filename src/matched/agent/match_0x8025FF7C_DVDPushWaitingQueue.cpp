// 0x8025FF7C __DVDPushWaitingQueue (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,4,0; stw 30,0x10(1); addi 30,3,0; bl _s8025FF7C_0; lis 4,-32694; rlwinm 5,30,3,0,28; addi 0,4,-17096; add 5,0,5; lwz 4,0x4(5); stw 31,0x0(4); lwz 0,0x4(5); stw 0,0x4(31); stw 5,0x0(31); stw 31,0x4(5); bl _s8025FF7C_1; lwz 0,0x1c(1); li 3,1; lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8025FF7C_0();
extern "C" void _s8025FF7C_1();
extern "C" void f_8025FF7C() {}
