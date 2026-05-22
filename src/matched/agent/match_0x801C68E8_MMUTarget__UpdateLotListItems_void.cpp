// 0x801C68E8 MMUTarget::UpdateLotListItems(void) (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-336(1); mfspr 0,8; stmw 23,0x12c(1); stw 0,0x154(1); mr 28,3; addi 3,1,8; li 30,0; bl _s801C68E8_0; lis 23,-32705; addi 24,1,42; addi 3,1,8; bl _s801C68E8_1; lis 9,-32705; addi 31,1,32; lwz 25,0x2cac(9); addi 29,1,288; addi 9,9,11436; lhz 26,0x8(9); lwz 27,0x4(9); 0:; stw 25,0x20(1); mr 3,24; li 4,0; li 5,245; stw 27,0x4(31); sth 26,0x8(31); crxor 6,6,6; bl _s801C68E8_2; mr 5,30; addi 4,23,-8800; mr 3,29; crxor 6,6,6; bl _s801C68E8_3; mr 4,29; mr 3,31; bl _s801C68E8_4; addi 3,1,8; mr 4,31; li 5,0; bl _s801C68E8_5; lwz 0,0xa0(28); cmplw 30,0; bge 1f; addi 3,1,8; li 4,1; bl _s801C68E8_6; b 2f; 1:; addi 3,1,8; li 4,0; bl _s801C68E8_7; 2:; lwz 0,0x98(28); cmpw 0,30; bne 3f; addi 3,1,8; lis 4,255; bl _s801C68E8_8; b 4f; 3:; lis 4,255; addi 3,1,8; ori 4,4,65535; bl _s801C68E8_9; 4:; addi 30,30,1; cmplwi 30,15; ble 0b; addi 3,1,8; bl _s801C68E8_10; addi 3,1,8; li 4,2; bl _s801C68E8_11; lwz 0,0x154(1); mtspr 8,0; lmw 23,0x12c(1); addi 1,1,336"
extern "C" void _s801C68E8_0();
extern "C" void _s801C68E8_1();
extern "C" void _s801C68E8_2();
extern "C" void _s801C68E8_3();
extern "C" void _s801C68E8_4();
extern "C" void _s801C68E8_5();
extern "C" void _s801C68E8_6();
extern "C" void _s801C68E8_7();
extern "C" void _s801C68E8_8();
extern "C" void _s801C68E8_9();
extern "C" void _s801C68E8_10();
extern "C" void _s801C68E8_11();
extern "C" void f_801C68E8() {}
