// 0x8025FAA0 DVDCancelAllAsync (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); mr 31,3; stw 30,0x18(1); stw 29,0x14(1); bl _s8025FAA0_0; mr 30,3; bl _s8025FAA0_1; lwz 0,-23480(13); li 4,1; stw 4,-23468(13); cmplwi 0,0; bne 0f; stw 4,-23464(13); 0:; bl _s8025FAA0_2; b 2f; 1:; li 4,0; bl _s8025FAA0_3; 2:; bl _s8025FAA0_4; cmplwi 3,0; bne 1b; lwz 3,-23480(13); cmplwi 3,0; beq 3f; mr 4,31; bl _s8025FAA0_5; mr 29,3; b 4f; 3:; cmplwi 31,0; li 29,1; beq 4f; addi 12,31,0; mtspr 8,12; li 3,0; li 4,0; blrl; 4:; bl _s8025FAA0_6; li 4,0; stw 4,-23468(13); mr 31,3; lwz 0,-23464(13); cmpwi 0,0; beq 5f; stw 4,-23464(13); bl _s8025FAA0_7; 5:; mr 3,31; bl _s8025FAA0_8; mr 3,30; bl _s8025FAA0_9; mr 3,29; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8025FAA0_0();
extern "C" void _s8025FAA0_1();
extern "C" void _s8025FAA0_2();
extern "C" void _s8025FAA0_3();
extern "C" void _s8025FAA0_4();
extern "C" void _s8025FAA0_5();
extern "C" void _s8025FAA0_6();
extern "C" void _s8025FAA0_7();
extern "C" void _s8025FAA0_8();
extern "C" void _s8025FAA0_9();
extern "C" void f_8025FAA0() {}
