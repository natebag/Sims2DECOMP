// 0x803922A4 __VMSwapPageIn (508 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stw 0,0x34(1); addi 11,1,48; bl _s803922A4_0; mr 27,3; bl _s803922A4_1; lis 6,-32768; lis 5,17180; lwz 0,0xf8(6); rlwinm 3,3,3,0,28; rlwimi 3,4,3,29,31; addi 5,5,-8573; rlwinm 0,0,30,2,31; rlwinm 4,4,3,0,28; mulhwu 0,5,0; li 5,0; rlwinm 6,0,17,15,31; bl _s803922A4_2; mr 31,4; rlwinm 26,27,0,0,19; li 29,0; bl _s803922A4_3; lwz 4,-21892(13); rlwinm 0,3,12,0,19; mr 28,3; add 30,4,0; bl _s803922A4_4; mr 23,3; bl _s803922A4_5; mr 24,3; 0:; bl _s803922A4_6; cmplwi 3,0; bne 0b; bl _s803922A4_7; cmplwi 23,0; rlwinm 25,3,0,16,31; beq 3f; mr 3,23; bl _s803922A4_8; cmpwi 3,0; beq 2f; mr 3,23; bl _s803922A4_9; mr 3,30; li 29,1; li 4,4096; bl _s803922A4_10; mr 3,23; bl _s803922A4_11; mr 5,3; mr 4,30; li 3,0; li 6,4096; bl _s803922A4_12; 1:; bl _s803922A4_13; cmplwi 3,0; bne 1b; 2:; mr 3,23; mr 4,28; bl _s803922A4_14; 3:; mr 3,26; bl _s803922A4_15; cmpwi 3,0; beq 5f; mr 3,26; bl _s803922A4_16; mr 5,3; mr 4,30; li 3,1; li 6,4096; bl _s803922A4_17; 4:; bl _s803922A4_18; cmplwi 3,0; bne 4b; mr 3,30; li 4,4096; bl _s803922A4_19; mr 3,30; li 4,4096; bl _s803922A4_20; b 6f; 5:; mr 3,26; bl _s803922A4_21; cmpwi 3,0; bne 6f; mr 3,26; bl _s803922A4_22; 6:; cmpwi 25,0; bne 7f; bl _s803922A4_23; 7:; mr 3,26; mr 4,30; mr 5,28; bl _s803922A4_24; mr 3,24; bl _s803922A4_25; lwz 0,-21880(13); cmplwi 0,0; beq 8f; bl _s803922A4_26; lis 6,-32768; lis 5,17180; lwz 0,0xf8(6); rlwinm 3,3,3,0,28; rlwimi 3,4,3,29,31; addi 5,5,-8573; rlwinm 0,0,30,2,31; rlwinm 4,4,3,0,28; mulhwu 0,5,0; li 5,0; rlwinm 6,0,17,15,31; bl _s803922A4_27; lwz 12,-21880(13); subf 6,31,4; mr 3,27; mr 4,30; mr 5,28; mr 7,29; mtspr 9,12; bctrl; 8:; addi 11,1,48; bl _s803922A4_28; lwz 0,0x34(1); mtspr 8,0; addi 1,1,48"
extern "C" void _s803922A4_0();
extern "C" void _s803922A4_1();
extern "C" void _s803922A4_2();
extern "C" void _s803922A4_3();
extern "C" void _s803922A4_4();
extern "C" void _s803922A4_5();
extern "C" void _s803922A4_6();
extern "C" void _s803922A4_7();
extern "C" void _s803922A4_8();
extern "C" void _s803922A4_9();
extern "C" void _s803922A4_10();
extern "C" void _s803922A4_11();
extern "C" void _s803922A4_12();
extern "C" void _s803922A4_13();
extern "C" void _s803922A4_14();
extern "C" void _s803922A4_15();
extern "C" void _s803922A4_16();
extern "C" void _s803922A4_17();
extern "C" void _s803922A4_18();
extern "C" void _s803922A4_19();
extern "C" void _s803922A4_20();
extern "C" void _s803922A4_21();
extern "C" void _s803922A4_22();
extern "C" void _s803922A4_23();
extern "C" void _s803922A4_24();
extern "C" void _s803922A4_25();
extern "C" void _s803922A4_26();
extern "C" void _s803922A4_27();
extern "C" void _s803922A4_28();
extern "C" void f_803922A4() {}
