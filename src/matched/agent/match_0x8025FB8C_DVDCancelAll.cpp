// 0x8025FB8C DVDCancelAll (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); stw 28,0x10(1); bl _s8025FB8C_0; li 0,0; stw 0,-23420(13); mr 31,3; bl _s8025FB8C_1; mr 29,3; bl _s8025FB8C_2; lwz 0,-23480(13); li 4,1; stw 4,-23468(13); cmplwi 0,0; bne 0f; stw 4,-23464(13); 0:; bl _s8025FB8C_3; b 2f; 1:; li 4,0; bl _s8025FB8C_4; 2:; bl _s8025FB8C_5; cmplwi 3,0; bne 1b; lwz 3,-23480(13); cmplwi 3,0; beq 3f; lis 4,-32730; addi 4,4,-828; bl _s8025FB8C_6; mr 30,3; b 4f; 3:; lis 3,-32730; addic. 0,3,-828; li 30,1; beq 4f; li 3,0; li 4,0; bl _s8025FB8C_7; 4:; bl _s8025FB8C_8; li 4,0; stw 4,-23468(13); mr 28,3; lwz 0,-23464(13); cmpwi 0,0; beq 5f; stw 4,-23464(13); bl _s8025FB8C_9; 5:; mr 3,28; bl _s8025FB8C_10; mr 3,29; bl _s8025FB8C_11; cmpwi 30,0; bne 6f; mr 3,31; bl _s8025FB8C_12; li 3,-1; b 8f; 6:; lwz 0,-23420(13); cmpwi 0,0; bne 7f; addi 3,13,-23488; bl _s8025FB8C_13; b 6b; 7:; mr 3,31; bl _s8025FB8C_14; li 3,0; 8:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8025FB8C_0();
extern "C" void _s8025FB8C_1();
extern "C" void _s8025FB8C_2();
extern "C" void _s8025FB8C_3();
extern "C" void _s8025FB8C_4();
extern "C" void _s8025FB8C_5();
extern "C" void _s8025FB8C_6();
extern "C" void _s8025FB8C_7();
extern "C" void _s8025FB8C_8();
extern "C" void _s8025FB8C_9();
extern "C" void _s8025FB8C_10();
extern "C" void _s8025FB8C_11();
extern "C" void _s8025FB8C_12();
extern "C" void _s8025FB8C_13();
extern "C" void _s8025FB8C_14();
extern "C" void f_8025FB8C() {}
