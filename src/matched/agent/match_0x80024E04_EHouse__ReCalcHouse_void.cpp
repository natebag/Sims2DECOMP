// 0x80024E04 EHouse::ReCalcHouse(void) (404 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,3; lwz 0,0x1c(30); cmpwi 0,0; beq 5f; lwz 0,0x18(30); cmpwi 0,0; beq 5f; lwz 11,-26392(13); li 28,0; lwz 9,0x0(11); lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,11,3; blrl; mr 3,30; bl _s80024E04_0; mr 3,30; bl _s80024E04_1; bl _s80024E04_2; lwz 29,-21472(13); lwz 9,0x4(29); lwz 0,0x8(9); stw 0,0x8(1); mr 31,0; lwz 9,0x4(29); cmpw 31,9; stw 9,0x8(1); beq 2f; 0:; lwz 3,0x14(31); cmpwi 3,0; beq 1f; lwz 0,0x34(3); cmpwi 0,0; beq 1f; bl _s80024E04_3; cmpwi 3,0; bne 1f; lhz 0,0x10(31); cmplw 0,28; ble 1f; mr 28,0; 1:; mr 3,31; bl _s80024E04_4; lwz 0,0x4(29); mr 31,3; cmpw 31,0; stw 0,0x8(1); bne 0b; 2:; lwz 9,0x1c(30); addi 0,28,1; li 11,-1; stw 0,0x2c(30); addis 9,9,3; li 3,180; stw 11,-15680(9); stw 11,-15684(9); bl _s80024E04_5; bl _s80024E04_6; mr 0,3; stw 0,0x8(30); bl _s80024E04_7; lwz 3,0x1c(30); bl _s80024E04_8; lwz 0,0x0(30); cmpwi 0,0; bne 4f; lwz 3,0x1c(30); bl _s80024E04_9; lwz 3,0x1c(30); lwz 4,0x2c(30); addis 9,3,3; lwz 0,-23884(9); cmpw 4,0; beq 3f; bl _s80024E04_10; 3:; mr 3,30; bl _s80024E04_11; mr 3,30; bl _s80024E04_12; lwz 3,-21484(13); lwz 9,0x0(3); lha 0,0x278(9); lwz 9,0x27c(9); add 3,3,0; mtspr 8,9; blrl; 4:; lwz 3,0x4(30); cmpwi 3,0; beq 5f; li 4,0; bl _s80024E04_13; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s80024E04_0();
extern "C" void _s80024E04_1();
extern "C" void _s80024E04_2();
extern "C" void _s80024E04_3();
extern "C" void _s80024E04_4();
extern "C" void _s80024E04_5();
extern "C" void _s80024E04_6();
extern "C" void _s80024E04_7();
extern "C" void _s80024E04_8();
extern "C" void _s80024E04_9();
extern "C" void _s80024E04_10();
extern "C" void _s80024E04_11();
extern "C" void _s80024E04_12();
extern "C" void _s80024E04_13();
extern "C" void f_80024E04() {}
