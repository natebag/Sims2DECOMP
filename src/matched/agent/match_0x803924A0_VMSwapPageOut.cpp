// 0x803924A0 __VMSwapPageOut (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 0,0x24(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); stw 28,0x10(1); mr 28,3; bl _s803924A0_0; mr 31,3; bl _s803924A0_1; mr 29,3; 0:; bl _s803924A0_2; cmplwi 3,0; bne 0b; bl _s803924A0_3; rlwinm 30,3,0,16,31; mr 3,31; li 4,4096; bl _s803924A0_4; mr 3,28; bl _s803924A0_5; mr 5,3; mr 4,31; li 3,0; li 6,4096; bl _s803924A0_6; 1:; bl _s803924A0_7; cmplwi 3,0; bne 1b; cmpwi 30,0; bne 2f; bl _s803924A0_8; 2:; mr 3,29; bl _s803924A0_9; mr 3,28; bl _s803924A0_10; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); mtspr 8,0; addi 1,1,32"
extern "C" void _s803924A0_0();
extern "C" void _s803924A0_1();
extern "C" void _s803924A0_2();
extern "C" void _s803924A0_3();
extern "C" void _s803924A0_4();
extern "C" void _s803924A0_5();
extern "C" void _s803924A0_6();
extern "C" void _s803924A0_7();
extern "C" void _s803924A0_8();
extern "C" void _s803924A0_9();
extern "C" void _s803924A0_10();
extern "C" void f_803924A0() {}
