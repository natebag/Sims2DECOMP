// 0x8019A200 CASSelectionTarget::LoadGridTextures(unsigned (548 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 23,0x14(1); stw 0,0x3c(1); mr 24,5; mr 29,3; cmplw 4,24; bge 14f; cmplwi 24,15; bgt 14f; mr 27,4; addi 25,29,148; rlwinm 28,27,2,0,29; lis 23,-32692; addi 0,28,1428; add 26,0,29; 0:; mr 3,29; mr 4,27; bl _s8019A200_0; lwz 0,0x8c(29); mr 31,3; cmpw 31,0; bge 1f; cmpwi 31,0; bge 6f; 1:; lwz 9,0x0(26); lwz 0,0x14(9); cmpwi 0,0; beq 2f; mr 3,0; b 3f; 2:; lwz 9,0x18(9); li 3,0; cmpwi 9,0; beq 3f; lwz 3,0x14(9); 3:; lwz 9,0xf0(3); lwz 11,0x5d4(29); lha 0,0x38(9); addi 30,9,56; lwz 9,0x14(11); add 31,3,0; cmpwi 9,0; beq 4f; mr 3,9; b 5f; 4:; lwz 9,0x18(11); li 3,0; cmpwi 9,0; beq 5f; lwz 3,0x14(9); 5:; li 4,0; bl _s8019A200_1; lwz 0,0x4(30); mr 4,3; mr 3,31; li 5,0; mtspr 8,0; blrl; b 13f; 6:; lwz 4,0x54c(29); mr 3,29; addi 5,1,8; li 30,0; bl _s8019A200_2; cmpwi 3,0; beq 7f; lbzx 5,25,31; lwz 3,0x84(29); lwz 4,0x8(1); bl _s8019A200_3; b 8f; 7:; lwz 4,0x54c(29); mr 3,29; addi 5,1,12; bl _s8019A200_4; cmpwi 3,0; beq 9f; lbzx 5,25,31; lwz 3,0x84(29); lwz 4,0xc(1); bl _s8019A200_5; 8:; mr 30,3; 9:; cmpwi 30,0; beq 13f; mr 4,30; addi 3,23,-7364; li 5,0; li 6,0; bl _s8019A200_6; addi 9,29,1364; addi 11,29,1428; stwx 3,9,28; mr 8,9; lwz 9,0x0(26); cmpwi 9,0; beq 13f; lwz 0,0x14(9); cmpwi 0,0; bne 10f; lwz 9,0x18(9); li 0,0; cmpwi 9,0; beq 10f; lwz 0,0x14(9); 10:; cmpwi 0,0; beq 13f; lwzx 9,11,28; lwz 3,0x14(9); cmpwi 3,0; beq 11f; mr 10,3; b 12f; 11:; lwz 9,0x18(9); li 10,0; cmpwi 9,0; beq 12f; lwz 10,0x14(9); 12:; lwz 9,0xf0(10); li 5,0; lwzx 11,8,28; lha 3,0x38(9); lwz 0,0x3c(9); add 3,10,3; lwz 4,0x14(11); mtspr 8,0; blrl; 13:; addi 27,27,1; addi 28,28,4; addi 26,26,4; cmplw 27,24; ble 0b; 14:; lwz 0,0x3c(1); mtspr 8,0; lmw 23,0x14(1); addi 1,1,56"
extern "C" void _s8019A200_0();
extern "C" void _s8019A200_1();
extern "C" void _s8019A200_2();
extern "C" void _s8019A200_3();
extern "C" void _s8019A200_4();
extern "C" void _s8019A200_5();
extern "C" void _s8019A200_6();
extern "C" void f_8019A200() {}
