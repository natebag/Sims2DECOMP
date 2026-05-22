// 0x8025472C OSWakeupThread (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s8025472C_0; lis 4,-32694; addi 31,3,0; addi 5,4,-24616; b 5f; 0:; lwz 3,0x2e0(6); cmplwi 3,0; bne 1f; li 0,0; stw 0,0x4(30); b 2f; 1:; li 0,0; stw 0,0x2e4(3); 2:; stw 3,0x0(30); li 0,1; sth 0,0x2c8(6); lwz 0,0x2cc(6); cmpwi 0,0; bgt 5f; lwz 0,0x2d0(6); rlwinm 0,0,3,0,28; add 0,5,0; stw 0,0x2dc(6); lwz 4,0x2dc(6); lwz 3,0x4(4); cmplwi 3,0; bne 3f; stw 6,0x0(4); b 4f; 3:; stw 6,0x2e0(3); 4:; stw 3,0x2e4(6); li 0,0; li 3,1; stw 0,0x2e0(6); lwz 4,0x2dc(6); stw 6,0x4(4); lwz 0,0x2d0(6); lwz 4,-23584(13); subfic 0,0,31; slw 0,3,0; or 0,4,0; stw 0,-23584(13); stw 3,-23580(13); 5:; lwz 6,0x0(30); cmplwi 6,0; bne 0b; lwz 0,-23580(13); cmpwi 0,0; beq 6f; li 3,0; bl _s8025472C_1; 6:; mr 3,31; bl _s8025472C_2; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8025472C_0();
extern "C" void _s8025472C_1();
extern "C" void _s8025472C_2();
extern "C" void f_8025472C() {}
