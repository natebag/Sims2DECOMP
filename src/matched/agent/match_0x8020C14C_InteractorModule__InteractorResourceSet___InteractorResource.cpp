// 0x8020C14C InteractorModule::InteractorResourceSet::~InteractorResourceSet(void) (520 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; addi 11,31,108; lwz 9,0x6c(31); lwz 0,0x4(11); cmpw 9,0; beq 1f; 0:; addi 9,9,56; cmpw 9,0; bne 0b; 1:; lwz 3,0x0(11); cmpwi 3,0; beq 3f; lwz 0,0xc(11); lis 9,-18725; ori 9,9,28087; subf 0,3,0; mullw 0,0,9; srawi 0,0,3; mulli 4,0,56; cmplwi 4,128; ble 2f; bl _s8020C14C_0; b 3f; 2:; bl _s8020C14C_1; 3:; lwz 3,0x5c(31); addi 9,31,92; cmpwi 3,0; beq 5f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 4f; bl _s8020C14C_2; b 5f; 4:; bl _s8020C14C_3; 5:; lwz 3,0x4c(31); addi 9,31,76; cmpwi 3,0; beq 7f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 6f; bl _s8020C14C_4; b 7f; 6:; bl _s8020C14C_5; 7:; lwz 3,0x3c(31); addi 9,31,60; cmpwi 3,0; beq 9f; lwz 0,0xc(9); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 8f; bl _s8020C14C_6; b 9f; 8:; bl _s8020C14C_7; 9:; addi 11,31,40; lwz 9,0x28(31); lwz 0,0x4(11); addi 30,31,20; cmpw 9,0; beq 11f; 10:; addi 9,9,8; cmpw 9,0; bne 10b; 11:; lwz 3,0x0(11); cmpwi 3,0; beq 13f; lwz 0,0xc(11); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 12f; bl _s8020C14C_8; b 13f; 12:; bl _s8020C14C_9; 13:; lwz 0,0x4(30); lwz 9,0x14(31); cmpw 9,0; beq 15f; 14:; addi 9,9,8; cmpw 9,0; bne 14b; 15:; lwz 3,0x0(30); cmpwi 3,0; beq 17f; lwz 0,0xc(30); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 16f; bl _s8020C14C_10; b 17f; 16:; bl _s8020C14C_11; 17:; lwz 9,0x0(31); lwz 0,0x4(31); mr 3,9; cmpw 9,0; beq 19f; 18:; addi 9,9,8; cmpw 9,0; bne 18b; 19:; cmpwi 3,0; beq 21f; lwz 0,0xc(31); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 20f; bl _s8020C14C_12; b 21f; 20:; bl _s8020C14C_13; 21:; andi. 0,29,1; beq 22f; mr 3,31; bl _s8020C14C_14; 22:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8020C14C_0();
extern "C" void _s8020C14C_1();
extern "C" void _s8020C14C_2();
extern "C" void _s8020C14C_3();
extern "C" void _s8020C14C_4();
extern "C" void _s8020C14C_5();
extern "C" void _s8020C14C_6();
extern "C" void _s8020C14C_7();
extern "C" void _s8020C14C_8();
extern "C" void _s8020C14C_9();
extern "C" void _s8020C14C_10();
extern "C" void _s8020C14C_11();
extern "C" void _s8020C14C_12();
extern "C" void _s8020C14C_13();
extern "C" void _s8020C14C_14();
extern "C" void f_8020C14C() {}
