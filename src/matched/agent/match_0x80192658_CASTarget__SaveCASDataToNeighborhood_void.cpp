// 0x80192658 CASTarget::SaveCASDataToNeighborhood(void) (468 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,3; li 26,1; lis 3,-32705; addi 3,3,-16176; bl _s80192658_0; cmpwi 3,5; beq 9f; lwz 0,0x104(30); cmpwi 0,3; bne 8f; lis 9,-32697; li 28,4; addi 27,9,23428; li 31,0; li 29,0; 0:; mr 9,31; cmpwi 31,0; bge 1f; addi 9,31,3; 1:; rlwinm 9,9,0,0,29; lwz 0,0x1348(30); subf 9,9,31; srw 0,0,9; andi. 0,0,1; beq 3f; cmpw 31,28; bge 2f; mr 28,31; 2:; mr 3,30; mr 4,31; bl _s80192658_1; b 4f; 3:; lwz 9,0x78(27); addi 9,9,1568; stwx 0,9,29; 4:; addi 31,31,1; addi 29,29,4; cmpwi 31,3; ble 0b; cmpwi 28,3; bgt 7f; lis 9,-32697; addi 29,9,23428; lwz 11,0x78(29); lwz 0,0x650(11); cmpwi 0,0; beq 6f; addi 31,30,5160; mr 3,31; bl _s80192658_2; cmpwi 3,0; ble 5f; lwz 9,0x78(29); mr 4,31; lwz 3,0x650(9); bl _s80192658_3; b 6f; 5:; mulli 0,28,392; lwz 4,0x78(29); lwz 3,0x650(4); add 4,4,0; addi 4,4,88; bl _s80192658_4; 6:; lis 3,-32697; addi 3,3,23428; bl _s80192658_5; cmpwi 3,0; beq 9f; lwz 11,-21476(13); lwz 9,0x0(11); lwz 0,0x194(9); lha 3,0x190(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); lwz 4,-32056(13); lha 0,0x68(9); lwz 9,0x6c(9); lwz 5,-32040(13); add 3,3,0; mtspr 8,9; blrl; b 9f; 7:; li 26,0; b 9f; 8:; mr 3,30; li 4,0; bl _s80192658_6; lwz 4,0x1360(30); addi 3,30,2632; bl _s80192658_7; lwz 11,-21476(13); lwz 9,0x0(11); lwz 0,0x194(9); lha 3,0x190(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); lwz 4,-32056(13); lha 0,0x68(9); lwz 9,0x6c(9); lwz 5,-32040(13); add 3,3,0; mtspr 8,9; blrl; 9:; mr 3,26; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80192658_0();
extern "C" void _s80192658_1();
extern "C" void _s80192658_2();
extern "C" void _s80192658_3();
extern "C" void _s80192658_4();
extern "C" void _s80192658_5();
extern "C" void _s80192658_6();
extern "C" void _s80192658_7();
extern "C" void f_80192658() {}
