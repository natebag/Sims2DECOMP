// 0x800F2DCC ObjectModuleImpl::~ObjectModuleImpl(void) (520 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 21,0xc(1); stw 0,0x3c(1); mr 30,3; lis 11,-32698; lwz 3,0x2090(30); lis 9,-32698; addi 11,11,6856; addi 9,9,6888; addi 10,30,8336; mr 21,4; stw 11,0x10(30); cmpwi 3,0; stw 9,0x0(30); beq 1f; lwz 0,0xc(10); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 0f; bl _s800F2DCC_0; b 1f; 0:; bl _s800F2DCC_1; 1:; addi 28,30,8312; lwz 31,0x2078(30); lwz 29,0x4(28); addi 27,30,8296; addi 26,30,8280; addi 25,30,8260; cmpw 31,29; addi 24,30,8244; addi 23,30,28; addi 22,30,4; beq 3f; 2:; lwz 9,0x0(31); li 4,2; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; addi 31,31,60; blrl; cmpw 31,29; bne 2b; 3:; lwz 3,0x0(28); cmpwi 3,0; beq 5f; lwz 0,0xc(28); lis 9,-4370; ori 9,9,61167; subf 0,3,0; mullw 0,0,9; srawi 0,0,2; mulli 4,0,60; cmplwi 4,128; ble 4f; bl _s800F2DCC_2; b 5f; 4:; bl _s800F2DCC_3; 5:; lwz 3,0x2068(30); cmpwi 3,0; beq 7f; lwz 0,0xc(27); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 6f; bl _s800F2DCC_4; b 7f; 6:; bl _s800F2DCC_5; 7:; lwz 3,0x2058(30); cmpwi 3,0; beq 9f; lwz 0,0xc(26); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 8f; bl _s800F2DCC_6; b 9f; 8:; bl _s800F2DCC_7; 9:; lwz 3,0x2044(30); cmpwi 3,0; beq 11f; lwz 0,0xc(25); subf 0,3,0; rlwinm 4,0,0,0,30; cmplwi 4,128; ble 10f; bl _s800F2DCC_8; b 11f; 10:; bl _s800F2DCC_9; 11:; lwz 3,0x2034(30); cmpwi 3,0; beq 13f; lwz 0,0xc(24); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 12f; bl _s800F2DCC_10; b 13f; 12:; bl _s800F2DCC_11; 13:; lwz 3,0x1c(30); cmpwi 3,0; beq 15f; lwz 0,0xc(23); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 14f; bl _s800F2DCC_12; b 15f; 14:; bl _s800F2DCC_13; 15:; mr 3,22; li 4,0; bl _s800F2DCC_14; lis 9,-32698; andi. 0,21,1; addi 9,9,7552; stw 9,0x0(30); beq 16f; mr 3,30; bl _s800F2DCC_15; 16:; lwz 0,0x3c(1); mtspr 8,0; lmw 21,0xc(1); addi 1,1,56"
extern "C" void _s800F2DCC_0();
extern "C" void _s800F2DCC_1();
extern "C" void _s800F2DCC_2();
extern "C" void _s800F2DCC_3();
extern "C" void _s800F2DCC_4();
extern "C" void _s800F2DCC_5();
extern "C" void _s800F2DCC_6();
extern "C" void _s800F2DCC_7();
extern "C" void _s800F2DCC_8();
extern "C" void _s800F2DCC_9();
extern "C" void _s800F2DCC_10();
extern "C" void _s800F2DCC_11();
extern "C" void _s800F2DCC_12();
extern "C" void _s800F2DCC_13();
extern "C" void _s800F2DCC_14();
extern "C" void _s800F2DCC_15();
extern "C" void f_800F2DCC() {}
