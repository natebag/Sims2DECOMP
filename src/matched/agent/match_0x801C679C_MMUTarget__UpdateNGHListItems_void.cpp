// 0x801C679C MMUTarget::UpdateNGHListItems(void) (332 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-336(1); mfspr 0,8; mfcr 12; stmw 23,0x12c(1); stw 0,0x154(1); stw 12,0x128(1); mr 28,3; li 30,0; lwz 0,0x8c(28); li 31,0; cmpwi 0,1; beq 0f; li 31,1; 0:; addi 3,1,8; cmpwi 4,31,0; bl _s801C679C_0; addi 3,1,8; addi 24,1,42; bl _s801C679C_1; lis 23,-32705; lis 9,-32705; addi 31,1,32; lwz 25,0x2cac(9); addi 29,1,288; addi 9,9,11436; lhz 26,0x8(9); lwz 27,0x4(9); 1:; stw 25,0x20(1); mr 3,24; li 4,0; li 5,245; stw 27,0x4(31); sth 26,0x8(31); crxor 6,6,6; bl _s801C679C_2; mr 5,30; addi 4,23,-8800; mr 3,29; crxor 6,6,6; bl _s801C679C_3; mr 4,29; mr 3,31; bl _s801C679C_4; addi 3,1,8; mr 4,31; li 5,0; bl _s801C679C_5; cmplwi 30,5; bgt 2f; bne cr4,2f; addi 3,1,8; li 4,1; bl _s801C679C_6; b 3f; 2:; addi 3,1,8; li 4,0; bl _s801C679C_7; 3:; lwz 0,0x9c(28); cmpw 0,30; bne 4f; addi 3,1,8; lis 4,255; bl _s801C679C_8; b 5f; 4:; lis 4,255; addi 3,1,8; ori 4,4,65535; bl _s801C679C_9; 5:; addi 30,30,1; cmplwi 30,15; ble 1b; addi 3,1,8; bl _s801C679C_10; addi 3,1,8; li 4,2; bl _s801C679C_11; lwz 0,0x154(1); lwz 12,0x128(1); mtspr 8,0; lmw 23,0x12c(1); mtcrf 8,12; addi 1,1,336"
extern "C" void _s801C679C_0();
extern "C" void _s801C679C_1();
extern "C" void _s801C679C_2();
extern "C" void _s801C679C_3();
extern "C" void _s801C679C_4();
extern "C" void _s801C679C_5();
extern "C" void _s801C679C_6();
extern "C" void _s801C679C_7();
extern "C" void _s801C679C_8();
extern "C" void _s801C679C_9();
extern "C" void _s801C679C_10();
extern "C" void _s801C679C_11();
extern "C" void f_801C679C() {}
