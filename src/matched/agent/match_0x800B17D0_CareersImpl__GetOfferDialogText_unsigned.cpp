// 0x800B17D0 CareersImpl::GetOfferDialogText(unsigned (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 27,0x2c(1); stw 0,0x44(1); mr 30,7; mr 27,4; mr 31,5; mr 28,6; addi 3,1,8; bl _s800B17D0_0; cmpwi 30,0; bne 2f; lwz 9,0xc(31); li 4,0; addi 30,1,16; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,30; bl _s800B17D0_1; mulli 0,28,112; lwz 9,0x4(31); addi 29,1,24; li 4,0; add 9,9,0; lwz 5,0x58(9); cmpwi 5,0; beq 1f; lwz 4,0x0(5); 1:; mr 3,29; bl _s800B17D0_2; addi 3,1,8; mr 4,30; bl _s800B17D0_3; addi 3,1,8; mr 4,29; bl _s800B17D0_4; addi 3,1,8; bl _s800B17D0_5; mr 4,3; mr 3,27; bl _s800B17D0_6; mr 3,29; li 4,2; bl _s800B17D0_7; mr 3,30; li 4,2; bl _s800B17D0_8; b 5f; 2:; lwz 9,0xc(31); li 4,0; addi 30,1,16; cmpwi 9,0; beq 3f; lwz 4,0x0(9); 3:; mr 3,30; bl _s800B17D0_9; mulli 0,28,112; lwz 9,0x4(31); addi 29,1,32; li 4,0; add 9,9,0; lwz 5,0x5c(9); cmpwi 5,0; beq 4f; lwz 4,0x0(5); 4:; mr 3,29; bl _s800B17D0_10; addi 3,1,8; mr 4,30; bl _s800B17D0_11; addi 3,1,8; mr 4,29; bl _s800B17D0_12; addi 3,1,8; bl _s800B17D0_13; mr 4,3; mr 3,27; bl _s800B17D0_14; mr 3,29; li 4,2; bl _s800B17D0_15; mr 3,30; li 4,2; bl _s800B17D0_16; 5:; addi 3,1,8; li 4,2; bl _s800B17D0_17; lwz 0,0x44(1); mtspr 8,0; lmw 27,0x2c(1); addi 1,1,64"
extern "C" void _s800B17D0_0();
extern "C" void _s800B17D0_1();
extern "C" void _s800B17D0_2();
extern "C" void _s800B17D0_3();
extern "C" void _s800B17D0_4();
extern "C" void _s800B17D0_5();
extern "C" void _s800B17D0_6();
extern "C" void _s800B17D0_7();
extern "C" void _s800B17D0_8();
extern "C" void _s800B17D0_9();
extern "C" void _s800B17D0_10();
extern "C" void _s800B17D0_11();
extern "C" void _s800B17D0_12();
extern "C" void _s800B17D0_13();
extern "C" void _s800B17D0_14();
extern "C" void _s800B17D0_15();
extern "C" void _s800B17D0_16();
extern "C" void _s800B17D0_17();
extern "C" void f_800B17D0() {}
