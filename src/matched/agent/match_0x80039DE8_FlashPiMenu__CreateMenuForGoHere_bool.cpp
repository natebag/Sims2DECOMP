// 0x80039DE8 FlashPiMenu::CreateMenuForGoHere(bool) (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 27,0x3c(1); stw 0,0x54(1); mr 31,3; lis 9,-32697; lwz 11,0x8(31); addi 9,9,24012; addi 29,9,188; mr 28,4; rlwinm 11,11,2,0,29; li 3,0; lwzx 0,29,11; cmpwi 0,0; beq 3f; mr 3,31; bl _s80039DE8_0; lwz 0,0x0(31); cmpwi 0,0; beq 2f; addi 30,1,16; addi 3,1,8; bl _s80039DE8_1; mr 27,30; lwz 0,0x8(31); mr 3,30; lwz 5,0x0(31); rlwinm 0,0,2,0,29; lwzx 4,29,0; bl _s80039DE8_2; lwz 5,-21280(13); mr 3,30; addi 4,1,8; bl _s80039DE8_3; addi 3,1,8; bl _s80039DE8_4; cmpwi 3,0; beq 1f; cmpwi 28,0; beq 0f; lwz 0,0x8(1); addi 30,1,8; lwz 4,0x0(31); li 6,0; mr 5,0; stw 0,0x30(1); mr 3,31; bl _s80039DE8_5; mr 3,31; bl _s80039DE8_6; mr 3,27; li 4,2; bl _s80039DE8_7; mr 3,30; li 4,2; bl _s80039DE8_8; b 2f; 0:; mr 3,31; addi 5,1,8; lwz 4,0x0(3); bl _s80039DE8_9; 1:; mr 3,27; li 4,2; bl _s80039DE8_10; addi 3,1,8; li 4,2; bl _s80039DE8_11; li 3,1; b 3f; 2:; li 3,0; 3:; lwz 0,0x54(1); mtspr 8,0; lmw 27,0x3c(1); addi 1,1,80"
extern "C" void _s80039DE8_0();
extern "C" void _s80039DE8_1();
extern "C" void _s80039DE8_2();
extern "C" void _s80039DE8_3();
extern "C" void _s80039DE8_4();
extern "C" void _s80039DE8_5();
extern "C" void _s80039DE8_6();
extern "C" void _s80039DE8_7();
extern "C" void _s80039DE8_8();
extern "C" void _s80039DE8_9();
extern "C" void _s80039DE8_10();
extern "C" void _s80039DE8_11();
extern "C" void f_80039DE8() {}
