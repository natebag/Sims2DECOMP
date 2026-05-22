// 0x80283FA0 AptAnimationPoolData::runActions(void) (800 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 19,0x14(1); stw 0,0x4c(1); mr 24,3; lwz 28,0x98(24); lwz 31,0x4(28); lwz 0,0x8(28); cmpw 31,0; beq 10f; lis 27,-32694; lis 20,-32704; addi 19,27,-16032; addi 25,1,9; addi 21,19,36; lis 22,-32704; lis 23,-32704; 0:; stw 31,0xc(28); lwz 0,0x0(31); cmpwi 0,1; bne 5f; lwz 0,0x4(31); lis 26,-32694; stw 0,0x3c(19); lwz 30,0x10(31); lwz 0,0x0(30); andis. 9,0,2048; beq 6f; mr 3,30; li 29,0; bl _s80283FA0_0; cmpwi 3,19; bne 1f; mr 3,30; bl _s80283FA0_1; subfic 0,3,0; adde 29,0,3; 1:; cmpwi 29,0; bne 6f; lwz 0,0x8(31); cmpwi 0,0; bge 2f; lwz 9,0x10(31); lwz 9,0x4c(9); cmpwi 9,0; beq 2f; lwz 9,0x18(9); neg 0,0; cmpw 0,9; bne 6f; 2:; addi 3,26,-16032; addi 4,1,8; bl _s80283FA0_2; mr 30,3; addi 29,1,8; lwz 3,0x10(31); cmpwi 3,0; beq 3f; bl _s80283FA0_3; lwz 7,0x4c(3); b 4f; 3:; li 7,0; 4:; lwz 9,0xc(31); li 6,-1; lwz 5,0x10(31); addi 3,27,-16032; lwz 4,0x0(9); bl _s80283FA0_4; addi 3,27,-16032; mr 4,30; mr 5,29; bl _s80283FA0_5; mr 3,24; bl _s80283FA0_6; b 6f; 5:; cmpwi 0,2; lis 26,-32694; bne 6f; lwz 0,0x4(31); addi 29,26,-16032; lwz 11,0x24(29); lis 4,-32704; stw 0,0x3c(29); addi 5,20,10808; rlwinm 9,11,2,0,29; li 6,120; lwz 10,0x8(31); addi 11,11,1; lwz 8,0x8(21); addi 4,4,12072; stwx 10,9,8; stw 11,0x24(29); lwz 9,0x8(10); lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,10,3; blrl; mr 4,25; mr 3,29; bl _s80283FA0_7; lwz 6,0x10(31); mr 30,3; lwz 4,0x8(31); mr 3,29; lwz 5,0xc(31); bl _s80283FA0_8; mr 4,30; mr 3,29; mr 5,25; bl _s80283FA0_9; lwz 11,0x24(29); lis 4,-32704; lwz 0,0x8(21); addi 4,4,10768; rlwinm 11,11,2,0,29; addi 5,20,10808; add 11,11,0; li 6,126; lwz 10,-4(11); lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; lwz 9,0x24(29); lwz 11,-16032(26); addi 9,9,-1; cmpwi 11,0; stw 9,0x24(29); ble 6f; lwz 0,0x8(29); rlwinm 11,11,2,0,29; addi 4,22,11492; addi 5,23,11340; add 11,11,0; li 6,160; lwz 10,-4(11); lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; lwz 9,-16032(26); addi 9,9,-1; stw 9,-16032(26); 6:; lwz 11,-16032(27); addi 9,27,-16032; cmpwi 11,0; ble 7f; lwz 0,0x8(9); rlwinm 11,11,2,0,29; addi 4,22,11492; addi 5,23,11340; add 11,11,0; li 6,160; lwz 10,-4(11); lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; lwz 9,-16032(26); addi 9,9,-1; stw 9,-16032(26); 7:; lwz 9,0x4(28); lwz 0,0x8(28); cmplw 9,0; bgt 8f; subfc 0,0,31; li 0,0; adde 0,0,0; b 9f; 8:; cmplw 31,0; li 0,0; blt 9f; subfc 0,9,31; subfe 0,0,0; neg 0,0; 9:; cmpwi 0,0; bne 10f; mr 4,31; mr 3,28; bl _s80283FA0_10; lwz 0,0x8(28); mr 31,3; cmpw 31,0; bne 0b; 10:; mr 3,24; bl _s80283FA0_11; mr 3,28; bl _s80283FA0_12; lwz 0,0x4c(1); mtspr 8,0; lmw 19,0x14(1); addi 1,1,72"
extern "C" void _s80283FA0_0();
extern "C" void _s80283FA0_1();
extern "C" void _s80283FA0_2();
extern "C" void _s80283FA0_3();
extern "C" void _s80283FA0_4();
extern "C" void _s80283FA0_5();
extern "C" void _s80283FA0_6();
extern "C" void _s80283FA0_7();
extern "C" void _s80283FA0_8();
extern "C" void _s80283FA0_9();
extern "C" void _s80283FA0_10();
extern "C" void _s80283FA0_11();
extern "C" void _s80283FA0_12();
extern "C" void f_80283FA0() {}
