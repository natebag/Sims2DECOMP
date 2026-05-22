// 0x801579F0 cXMTObjectImpl::GetISimInstance(void) (596 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="srawi 0,0,2; mulli 4,0,20; cmplwi 4,128; ble 0f; bl _s801579F0_0; b 1f; 0:; bl _s801579F0_1; 1:; lwz 9,0x30(1); lwz 0,0x34(1); mr 3,9; cmpw 9,0; beq 3f; 2:; addi 9,9,20; cmpw 9,0; bne 2b; 3:; cmpwi 3,0; beq 5f; lwz 0,0x3c(1); lis 9,-13108; ori 9,9,52429; subf 0,3,0; mullw 0,0,9; srawi 0,0,2; mulli 4,0,20; cmplwi 4,128; ble 4f; bl _s801579F0_2; b 5f; 4:; bl _s801579F0_3; 5:; lwz 9,0x20(1); lwz 0,0x24(1); mr 3,9; cmpw 9,0; beq 7f; 6:; addi 9,9,20; cmpw 9,0; bne 6b; 7:; cmpwi 3,0; beq 9f; lwz 0,0x2c(1); lis 9,-13108; ori 9,9,52429; subf 0,3,0; mullw 0,0,9; srawi 0,0,2; mulli 4,0,20; cmplwi 4,128; ble 8f; bl _s801579F0_4; b 9f; 8:; bl _s801579F0_5; 9:; li 3,1; b 24f; li 0,3; mr 3,18; stw 0,0x8c(22); li 4,2; bl _s801579F0_6; lwz 3,0xa8(1); cmpwi 3,0; beq 11f; lwz 0,0xb4(1); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 10f; bl _s801579F0_7; b 11f; 10:; bl _s801579F0_8; 11:; lwz 9,0x40(1); lwz 0,0x44(1); mr 3,9; cmpw 9,0; beq 13f; 12:; addi 9,9,20; cmpw 9,0; bne 12b; 13:; cmpwi 3,0; beq 15f; lwz 0,0x4c(1); lis 9,-13108; ori 9,9,52429; subf 0,3,0; mullw 0,0,9; srawi 0,0,2; mulli 4,0,20; cmplwi 4,128; ble 14f; bl _s801579F0_9; b 15f; 14:; bl _s801579F0_10; 15:; lwz 9,0x30(1); lwz 0,0x34(1); mr 3,9; cmpw 9,0; beq 17f; 16:; addi 9,9,20; cmpw 9,0; bne 16b; 17:; cmpwi 3,0; beq 19f; lwz 0,0x3c(1); lis 9,-13108; ori 9,9,52429; subf 0,3,0; mullw 0,0,9; srawi 0,0,2; mulli 4,0,20; cmplwi 4,128; ble 18f; bl _s801579F0_11; b 19f; 18:; bl _s801579F0_12; 19:; lwz 9,0x20(1); lwz 0,0x24(1); mr 3,9; cmpw 9,0; beq 21f; 20:; addi 9,9,20; cmpw 9,0; bne 20b; 21:; cmpwi 3,0; beq 23f; lwz 0,0x2c(1); lis 9,-13108; ori 9,9,52429; subf 0,3,0; mullw 0,0,9; srawi 0,0,2; mulli 4,0,20; cmplwi 4,128; ble 22f; bl _s801579F0_13; b 23f; 22:; bl _s801579F0_14; 23:; li 3,0; 24:; lwz 0,0x2bc(1); lwz 12,0x23c(1); mtspr 8,0; lmw 14,0x240(1); lfd f26,0x288(1); lfd f27,0x290(1); lfd f28,0x298(1); lfd f29,0x2a0(1); lfd f30,0x2a8(1); lfd f31,0x2b0(1); mtcrf 8,12; addi 1,1,696"
extern "C" void _s801579F0_0();
extern "C" void _s801579F0_1();
extern "C" void _s801579F0_2();
extern "C" void _s801579F0_3();
extern "C" void _s801579F0_4();
extern "C" void _s801579F0_5();
extern "C" void _s801579F0_6();
extern "C" void _s801579F0_7();
extern "C" void _s801579F0_8();
extern "C" void _s801579F0_9();
extern "C" void _s801579F0_10();
extern "C" void _s801579F0_11();
extern "C" void _s801579F0_12();
extern "C" void _s801579F0_13();
extern "C" void _s801579F0_14();
extern "C" void f_801579F0() {}
