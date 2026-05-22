// 0x8025884C QueueLength (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 5,3; stw 0,0x4(1); stwu 1,-16(1); lwz 3,-23560(13); lwz 4,-23556(13); bl _s8025884C_0; cmpwi 3,0; bne 0f; li 3,-1; b 1f; 0:; lis 0,8193; lwz 3,-23560(13); stw 0,0x8(1); addi 4,1,8; li 5,4; li 6,1; li 7,0; bl _s8025884C_1; lwz 3,-23560(13); bl _s8025884C_2; lwz 3,-23560(13); addi 4,1,8; li 5,1; li 6,0; li 7,0; bl _s8025884C_3; lwz 3,-23560(13); bl _s8025884C_4; lwz 3,-23560(13); bl _s8025884C_5; lwz 0,0x8(1); rlwinm 0,0,8,24,31; subfic 3,0,16; 1:; lwz 0,0x14(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8025884C_0();
extern "C" void _s8025884C_1();
extern "C" void _s8025884C_2();
extern "C" void _s8025884C_3();
extern "C" void _s8025884C_4();
extern "C" void _s8025884C_5();
extern "C" void f_8025884C() {}
