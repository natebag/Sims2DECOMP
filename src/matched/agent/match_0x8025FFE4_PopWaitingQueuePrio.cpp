// 0x8025FFE4 PopWaitingQueuePrio (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; bl _s8025FFE4_0; lis 4,-32694; rlwinm 5,31,3,0,28; addi 0,4,-17096; add 5,0,5; lwz 31,0x0(5); lwz 0,0x0(31); stw 0,0x0(5); lwz 4,0x0(31); stw 5,0x4(4); bl _s8025FFE4_1; li 0,0; stw 0,0x0(31); mr 3,31; stw 0,0x4(31); lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8025FFE4_0();
extern "C" void _s8025FFE4_1();
extern "C" void f_8025FFE4() {}
