// 0x80044BCC HoodManager::GetRelatedPeople(int, (660 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 23,0x2c(1); stw 0,0x54(1); mr 31,5; lwz 27,-21476(13); lwz 0,0x0(31); mr 23,3; li 24,0; stw 0,0x4(31); lwz 11,0x0(4); lwz 30,0x0(27); lwz 9,0x4(11); lha 29,0xc0(30); lwz 0,0x314(9); addi 30,30,192; lha 3,0x310(9); add 29,27,29; mtspr 8,0; add 3,11,3; blrl; lwz 0,0x4(30); lwz 4,0x1c(3); mr 3,29; mtspr 8,0; blrl; mr 25,3; b 12f; 0:; lwz 9,0x0(27); mr 4,3; lwz 0,0xbc(9); lha 3,0xb8(9); mtspr 8,0; add 3,27,3; blrl; mr. 0,3; stw 3,0x18(1); beq 12f; cmpw 0,25; beq 12f; mr 3,0; bl _s80044BCC_0; cmpwi 3,0; beq 12f; lwz 9,0x18(1); lwz 3,0xc(9); bl _s80044BCC_1; lwz 4,0x18(1); lha 0,0xea(4); cmpwi 0,0; beq 12f; mr 3,25; addi 5,1,16; addi 6,1,20; bl _s80044BCC_2; cmpwi 3,0; beq 12f; lwz 3,0x10(1); lwz 4,0x14(1); lwz 9,0x0(3); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; ble 12f; lwz 11,0x4(31); addi 26,1,24; lwz 0,0xc(31); mr 30,11; cmpw 11,0; beq 1f; lwz 0,0x18(1); stw 0,0x0(11); lwz 9,0x4(31); addi 9,9,4; stw 9,0x4(31); b 12f; 1:; lwz 9,0x0(31); li 0,1; stw 0,0x20(1); subf 9,9,11; addi 0,1,32; srawi 9,9,2; addi 11,1,28; stw 9,0x1c(1); cmplwi 9,1; bge 2f; mr 11,0; 2:; lwz 0,0x0(11); add. 3,9,0; beq 4f; rlwinm 3,3,2,0,29; cmplwi 3,128; mr 28,3; ble 3f; bl _s80044BCC_3; mr 29,3; b 5f; 3:; bl _s80044BCC_4; mr 29,3; b 5f; 4:; li 29,0; li 28,0; 5:; lwz 4,0x0(31); cmpw 30,4; beq 6f; subf 30,4,30; mr 3,29; mr 5,30; bl _s80044BCC_5; add 3,3,30; b 7f; 6:; mr 3,29; 7:; lwz 0,0x20(1); mr 30,3; mtspr 9,0; cmpwi 0,0; beq 9f; 8:; lwz 0,0x0(26); stw 0,0x0(30); addi 30,30,4; bdnz 8b; 9:; lwz 3,0x0(31); lwz 0,0xc(31); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 11f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 10f; bl _s80044BCC_6; b 11f; 10:; bl _s80044BCC_7; 11:; add 0,28,29; stw 29,0x0(31); stw 30,0x4(31); stw 0,0xc(31); 12:; lwz 9,0x0(27); mr 4,24; lha 3,0xe0(9); lwz 0,0xe4(9); add 3,27,3; mtspr 8,0; blrl; mr 24,3; cmpwi 3,0; bne 0b; lwz 3,0x0(31); lwz 4,0x4(31); subf 0,3,4; srawi 0,0,2; cmplwi 0,1; ble 13f; stw 23,0xc(1); addi 5,1,12; stw 23,0x8(1); bl _s80044BCC_8; 13:; lwz 0,0x54(1); mtspr 8,0; lmw 23,0x2c(1); addi 1,1,80"
extern "C" void _s80044BCC_0();
extern "C" void _s80044BCC_1();
extern "C" void _s80044BCC_2();
extern "C" void _s80044BCC_3();
extern "C" void _s80044BCC_4();
extern "C" void _s80044BCC_5();
extern "C" void _s80044BCC_6();
extern "C" void _s80044BCC_7();
extern "C" void _s80044BCC_8();
extern "C" void f_80044BCC() {}
