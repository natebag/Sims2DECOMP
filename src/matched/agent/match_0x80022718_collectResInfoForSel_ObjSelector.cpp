// 0x80022718 collectResInfoForSel(ObjSelector (468 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 30,3; mr 31,4; lis 3,-32692; lis 4,3123; addi 3,3,-20832; ori 4,4,56129; bl _s80022718_0; mr. 3,3; beq 13f; lwz 4,0x54(30); cmpwi 4,0; beq 13f; addi 5,1,8; bl _s80022718_1; mr. 3,3; beq 0f; lwz 3,0x8(3); cmpwi 3,0; beq 0f; lwz 9,0x8(1); rlwinm 9,9,2,0,29; lwzx 3,9,3; b 1f; 0:; li 3,0; 1:; cmpwi 3,0; beq 13f; bl _s80022718_2; stw 3,0xc(1); mr 3,31; lwz 4,0xc(1); bl _s80022718_3; cmpwi 3,0; bne 13f; lwz 9,0x4(31); addi 27,1,12; lwz 0,0xc(31); mr 30,9; cmpw 9,0; beq 2f; lwz 0,0xc(1); stw 0,0x0(30); lwz 9,0x4(31); addi 9,9,4; stw 9,0x4(31); b 13f; 2:; lwz 9,0x0(31); li 0,1; stw 0,0x14(1); addi 11,1,16; subf 9,9,30; addi 0,1,20; srawi 9,9,2; stw 9,0x10(1); cmplwi 9,1; bge 3f; mr 11,0; 3:; lwz 0,0x0(11); add. 0,9,0; beq 5f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 4f; mr 3,28; bl _s80022718_4; mr 29,3; b 6f; 4:; mr 3,28; bl _s80022718_5; mr 29,3; b 6f; 5:; li 29,0; li 28,0; 6:; lwz 4,0x0(31); cmpw 30,4; beq 7f; subf 30,4,30; mr 3,29; mr 5,30; bl _s80022718_6; add 3,3,30; b 8f; 7:; mr 3,29; 8:; lwz 0,0x14(1); mr 30,3; mtspr 9,0; cmpwi 0,0; beq 10f; 9:; lwz 0,0x0(27); stw 0,0x0(30); addi 30,30,4; bdnz 9b; 10:; lwz 3,0x0(31); lwz 0,0xc(31); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 12f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 11f; bl _s80022718_7; b 12f; 11:; bl _s80022718_8; 12:; add 0,28,29; stw 29,0x0(31); stw 0,0xc(31); stw 30,0x4(31); 13:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s80022718_0();
extern "C" void _s80022718_1();
extern "C" void _s80022718_2();
extern "C" void _s80022718_3();
extern "C" void _s80022718_4();
extern "C" void _s80022718_5();
extern "C" void _s80022718_6();
extern "C" void _s80022718_7();
extern "C" void _s80022718_8();
extern "C" void f_80022718() {}
