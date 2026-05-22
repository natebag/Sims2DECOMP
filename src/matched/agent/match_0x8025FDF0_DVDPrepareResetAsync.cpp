// 0x8025FDF0 __DVDPrepareResetAsync (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); mr 30,3; stw 29,0x14(1); bl _s8025FDF0_0; mr 29,3; bl _s8025FDF0_1; lwz 0,-23448(13); cmplwi 0,0; beq 0f; stw 30,-23444(13); b 8f; 0:; lwz 3,-23480(13); cmplwi 3,0; beq 1f; li 0,0; stw 0,0x28(3); 1:; bl _s8025FDF0_2; mr 31,3; bl _s8025FDF0_3; lwz 0,-23480(13); li 4,1; stw 4,-23468(13); cmplwi 0,0; bne 2f; stw 4,-23464(13); 2:; bl _s8025FDF0_4; b 4f; 3:; li 4,0; bl _s8025FDF0_5; 4:; bl _s8025FDF0_6; cmplwi 3,0; bne 3b; lwz 3,-23480(13); cmplwi 3,0; beq 5f; mr 4,30; bl _s8025FDF0_7; b 6f; 5:; cmplwi 30,0; beq 6f; addi 12,30,0; mtspr 8,12; li 3,0; li 4,0; blrl; 6:; bl _s8025FDF0_8; li 4,0; stw 4,-23468(13); mr 30,3; lwz 0,-23464(13); cmpwi 0,0; beq 7f; stw 4,-23464(13); bl _s8025FDF0_9; 7:; mr 3,30; bl _s8025FDF0_10; mr 3,31; bl _s8025FDF0_11; 8:; mr 3,29; bl _s8025FDF0_12; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8025FDF0_0();
extern "C" void _s8025FDF0_1();
extern "C" void _s8025FDF0_2();
extern "C" void _s8025FDF0_3();
extern "C" void _s8025FDF0_4();
extern "C" void _s8025FDF0_5();
extern "C" void _s8025FDF0_6();
extern "C" void _s8025FDF0_7();
extern "C" void _s8025FDF0_8();
extern "C" void _s8025FDF0_9();
extern "C" void _s8025FDF0_10();
extern "C" void _s8025FDF0_11();
extern "C" void _s8025FDF0_12();
extern "C" void f_8025FDF0() {}
