// 0x80113520 PassiveInfluenceMap::AddItemToMap(PassiveInfluenceItem (544 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 24,0x18(1); stw 0,0x3c(1); mr 11,4; mr 25,3; lwz 9,0x0(11); stw 4,0x8(1); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); lwz 0,0x4(3); subf 0,9,0; rlwinm. 9,0,29,3,31; beq 0f; lwz 4,0x8(1); mr 3,25; bl _s80113520_0; 0:; lwz 4,0x8(1); mr 3,25; li 27,0; bl _s80113520_1; lwz 11,0x8(1); lwz 9,0x0(11); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,11,3; blrl; mr 26,3; lwz 9,0x0(26); lwz 0,0x4(26); subf 0,9,0; rlwinm. 9,0,29,3,31; beq 14f; addi 24,1,8; 1:; lwz 9,0x0(26); rlwinm 11,27,3,0,28; lwz 8,0x4(25); lwzx 0,9,11; add 9,9,11; mullw 0,0,8; lwz 10,0x4(9); lwz 11,0x8(25); add 0,0,10; rlwinm 9,0,4,0,27; add 31,11,9; lwz 30,0x4(31); lwz 0,0xc(31); cmpw 30,0; beq 2f; lwz 0,0x8(1); addi 27,27,1; stw 0,0x0(30); lwz 9,0x4(31); addi 9,9,4; stw 9,0x4(31); b 13f; 2:; lwzx 0,11,9; addi 10,1,16; li 9,1; addi 11,1,12; subf 0,0,30; stw 9,0x10(1); srawi 9,0,2; stw 9,0xc(1); cmplwi 9,1; bge 3f; mr 11,10; 3:; lwz 0,0x0(11); add. 0,9,0; beq 5f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 4f; mr 3,28; bl _s80113520_2; mr 29,3; b 6f; 4:; mr 3,28; bl _s80113520_3; mr 29,3; b 6f; 5:; li 29,0; li 28,0; 6:; lwz 4,0x0(31); cmpw 30,4; beq 7f; subf 30,4,30; mr 3,29; mr 5,30; bl _s80113520_4; add 0,3,30; b 8f; 7:; mr 0,29; 8:; lwz 9,0x10(1); mr 30,0; addi 27,27,1; mtspr 9,9; cmpwi 9,0; beq 10f; 9:; lwz 0,0x0(24); stw 0,0x0(30); addi 30,30,4; bdnz 9b; 10:; lwz 3,0x0(31); lwz 0,0xc(31); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 12f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 11f; bl _s80113520_5; b 12f; 11:; bl _s80113520_6; 12:; add 0,28,29; stw 29,0x0(31); stw 0,0xc(31); stw 30,0x4(31); 13:; lwz 9,0x4(26); lwz 0,0x0(26); subf 9,0,9; srawi 9,9,3; cmplw 27,9; blt 1b; 14:; lwz 0,0x3c(1); mtspr 8,0; lmw 24,0x18(1); addi 1,1,56"
extern "C" void _s80113520_0();
extern "C" void _s80113520_1();
extern "C" void _s80113520_2();
extern "C" void _s80113520_3();
extern "C" void _s80113520_4();
extern "C" void _s80113520_5();
extern "C" void _s80113520_6();
extern "C" void f_80113520() {}
