// 0x800228EC collectResInfoForMultSel(ObjSelector (848 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 24,0x20(1); stw 0,0x44(1); mr 11,3; mr 25,4; lwz 9,0x38(11); mr 29,5; stw 3,0x14(1); lwz 0,0xc0(9); cmpwi 0,0; bne 13f; lwz 26,-21508(13); li 4,0; lha 24,0x14(9); lwz 9,0x0(26); lha 3,0x70(9); lwz 0,0x74(9); add 3,26,3; mtspr 8,0; blrl; cmpwi 3,0; stw 3,0x8(1); beq 25f; 0:; lwz 3,0x8(1); lwz 9,0x38(3); lha 0,0x14(9); cmpw 0,24; bne 12f; lwz 0,0xc0(9); cmpwi 0,0; beq 12f; lwz 4,0x14(1); bl _s800228EC_0; cmpwi 3,0; beq 12f; lwz 3,0x8(1); mr 4,25; bl _s800228EC_1; cmpwi 29,0; beq 12f; lwz 9,0x4(29); addi 27,1,8; lwz 0,0xc(29); mr 30,9; cmpw 9,0; beq 1f; lwz 0,0x8(1); stw 0,0x0(30); lwz 9,0x4(29); addi 9,9,4; stw 9,0x4(29); b 12f; 1:; lwz 9,0x0(29); li 0,1; stw 0,0x10(1); addi 11,1,12; subf 9,9,30; addi 0,1,16; srawi 9,9,2; stw 9,0xc(1); cmplwi 9,1; bge 2f; mr 11,0; 2:; lwz 0,0x0(11); add. 0,9,0; beq 4f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 3f; mr 3,28; bl _s800228EC_2; mr 31,3; b 5f; 3:; mr 3,28; bl _s800228EC_3; mr 31,3; b 5f; 4:; li 31,0; li 28,0; 5:; lwz 4,0x0(29); cmpw 30,4; beq 6f; subf 30,4,30; mr 3,31; mr 5,30; bl _s800228EC_4; add 3,3,30; b 7f; 6:; mr 3,31; 7:; lwz 0,0x10(1); mr 30,3; mtspr 9,0; cmpwi 0,0; beq 9f; 8:; lwz 0,0x0(27); stw 0,0x0(30); addi 30,30,4; bdnz 8b; 9:; lwz 3,0x0(29); lwz 0,0xc(29); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 11f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 10f; bl _s800228EC_5; b 11f; 10:; bl _s800228EC_6; 11:; add 0,28,31; stw 31,0x0(29); stw 30,0x4(29); stw 0,0xc(29); 12:; lwz 9,0x0(26); lwz 4,0x8(1); lha 3,0x70(9); lwz 0,0x74(9); add 3,26,3; mtspr 8,0; blrl; cmpwi 3,0; stw 3,0x8(1); bne 0b; b 25f; 13:; mr 3,11; mr 4,25; bl _s800228EC_7; cmpwi 29,0; beq 25f; lwz 9,0x4(29); addi 27,1,20; lwz 0,0xc(29); mr 30,9; cmpw 9,0; beq 14f; lwz 0,0x14(1); stw 0,0x0(30); lwz 9,0x4(29); addi 9,9,4; stw 9,0x4(29); b 25f; 14:; lwz 9,0x0(29); li 0,1; stw 0,0x1c(1); addi 11,1,24; subf 9,9,30; addi 0,1,28; srawi 9,9,2; stw 9,0x18(1); cmplwi 9,1; bge 15f; mr 11,0; 15:; lwz 0,0x0(11); add. 0,9,0; beq 17f; rlwinm 0,0,2,0,29; mr 31,0; cmplwi 0,128; ble 16f; mr 3,31; bl _s800228EC_8; mr 28,3; b 18f; 16:; mr 3,31; bl _s800228EC_9; mr 28,3; b 18f; 17:; li 28,0; li 31,0; 18:; lwz 4,0x0(29); cmpw 30,4; beq 19f; subf 30,4,30; mr 3,28; mr 5,30; bl _s800228EC_10; add 3,3,30; b 20f; 19:; mr 3,28; 20:; lwz 0,0x1c(1); mr 30,3; mtspr 9,0; cmpwi 0,0; beq 22f; 21:; lwz 0,0x0(27); stw 0,0x0(30); addi 30,30,4; bdnz 21b; 22:; lwz 3,0x0(29); lwz 0,0xc(29); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 24f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 23f; bl _s800228EC_11; b 24f; 23:; bl _s800228EC_12; 24:; add 0,31,28; stw 28,0x0(29); stw 0,0xc(29); stw 30,0x4(29); 25:; lwz 0,0x44(1); mtspr 8,0; lmw 24,0x20(1); addi 1,1,64"
extern "C" void _s800228EC_0();
extern "C" void _s800228EC_1();
extern "C" void _s800228EC_2();
extern "C" void _s800228EC_3();
extern "C" void _s800228EC_4();
extern "C" void _s800228EC_5();
extern "C" void _s800228EC_6();
extern "C" void _s800228EC_7();
extern "C" void _s800228EC_8();
extern "C" void _s800228EC_9();
extern "C" void _s800228EC_10();
extern "C" void _s800228EC_11();
extern "C" void _s800228EC_12();
extern "C" void f_800228EC() {}
