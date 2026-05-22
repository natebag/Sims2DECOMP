// 0x800507E8 ISimsObjectModel::animEventHandler(ERAnim (792 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 27,0x5c(1); stw 0,0x74(1); mr 28,5; mr 31,3; lwz 0,0x4(28); cmpwi 0,6; beq 2f; ble 0f; cmpwi 0,9; ble 23f; cmpwi 0,10; beq 15f; b 23f; 0:; cmpwi 0,0; blt 23f; cmpwi 0,4; ble 23f; lwz 0,0x49c(31); cmpwi 0,0; bne 23f; lwz 29,-21492(13); cmpwi 29,0; beq 23f; lwz 5,0x328(31); cmpwi 5,0; beq 1f; lwz 9,0x4(5); lwz 30,0x8(28); lha 3,0x328(9); lwz 0,0x32c(9); add 3,5,3; mtspr 8,0; blrl; mr 5,3; mr 4,30; mr 3,29; bl _s800507E8_0; b 23f; 1:; lwz 4,0x8(28); mr 3,29; li 5,0; bl _s800507E8_1; b 23f; 2:; lwz 3,0x8(28); addi 27,1,72; addi 29,31,1188; bl _s800507E8_2; lwz 30,0x4(29); lwz 0,0xc(29); stw 3,0x48(1); cmpw 30,0; beq 3f; stw 3,0x0(30); lwz 9,0x4(29); addi 9,9,4; stw 9,0x4(29); b 14f; 3:; lwz 0,0x4a4(31); li 9,1; stw 9,0x50(1); addi 11,1,80; subf 0,0,30; addi 9,1,76; srawi 3,0,2; stw 3,0x4c(1); cmplwi 3,1; bge 4f; mr 9,11; 4:; lwz 0,0x0(9); add. 0,3,0; beq 6f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 5f; mr 3,28; bl _s800507E8_3; mr 31,3; b 7f; 5:; mr 3,28; bl _s800507E8_4; mr 31,3; b 7f; 6:; li 31,0; li 28,0; 7:; lwz 4,0x0(29); cmpw 30,4; beq 8f; subf 30,4,30; mr 3,31; mr 5,30; bl _s800507E8_5; add 0,3,30; b 9f; 8:; mr 0,31; 9:; lwz 9,0x50(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 11f; 10:; lwz 0,0x0(27); stw 0,0x0(30); addi 30,30,4; bdnz 10b; 11:; lwz 3,0x0(29); lwz 0,0xc(29); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 13f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 12f; bl _s800507E8_6; b 13f; 12:; bl _s800507E8_7; 13:; add 0,28,31; stw 31,0x0(29); stw 0,0xc(29); stw 30,0x4(29); 14:; li 3,1; b 24f; 15:; lis 3,-32692; lwz 4,0x8(28); addi 3,3,-4004; li 30,0; bl _s800507E8_8; mr. 3,3; beq 18f; lwz 30,0x440(31); lwz 11,0x3cc(31); b 17f; 16:; lwz 30,0x8(30); 17:; cmpwi 30,0; beq 19f; lwz 9,0x0(30); lwz 0,0xc(9); cmpw 0,3; bne 16b; 18:; cmpwi 30,0; lwz 11,0x3cc(31); bne 21f; 19:; rlwinm 0,11,0,2,0; li 3,16; stw 0,0x3cc(31); bl _s800507E8_9; bl _s800507E8_10; lwz 9,0x0(31); mr 30,3; addi 4,1,8; lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,31,3; blrl; lwz 3,0x8(28); bl _s800507E8_11; addi 5,31,1056; lis 9,-32707; stw 3,0x4(5); addi 4,1,8; lfs f1,0x3250(9); mr 3,30; bl _s800507E8_12; cmpwi 3,0; beq 20f; addi 3,31,1088; mr 4,30; bl _s800507E8_13; b 23f; 20:; cmpwi 30,0; beq 23f; mr 3,30; li 4,3; bl _s800507E8_14; b 23f; 21:; oris 0,11,16384; addi 29,31,1088; stw 0,0x3cc(31); lwz 0,0x8(29); lwz 3,0x0(30); cmpwi 0,0; beq 22f; cmpwi 3,0; beq 22f; li 4,3; bl _s800507E8_15; 22:; mr 3,29; mr 4,30; bl _s800507E8_16; 23:; li 3,0; 24:; lwz 0,0x74(1); mtspr 8,0; lmw 27,0x5c(1); addi 1,1,112"
extern "C" void _s800507E8_0();
extern "C" void _s800507E8_1();
extern "C" void _s800507E8_2();
extern "C" void _s800507E8_3();
extern "C" void _s800507E8_4();
extern "C" void _s800507E8_5();
extern "C" void _s800507E8_6();
extern "C" void _s800507E8_7();
extern "C" void _s800507E8_8();
extern "C" void _s800507E8_9();
extern "C" void _s800507E8_10();
extern "C" void _s800507E8_11();
extern "C" void _s800507E8_12();
extern "C" void _s800507E8_13();
extern "C" void _s800507E8_14();
extern "C" void _s800507E8_15();
extern "C" void _s800507E8_16();
extern "C" void f_800507E8() {}
