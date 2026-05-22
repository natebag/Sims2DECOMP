// 0x802874E0 AptArray::scriptFunctionSortFunc(void (368 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 24,0x10(1); stw 0,0x34(1); lwz 0,-27540(13); cmpwi 0,0; bne 0f; li 3,0; b 2f; 0:; lis 31,-32694; addi 25,1,8; lwz 30,0x0(4); addi 27,31,-16032; lwz 29,0x0(3); mr 4,25; mr 3,27; lis 28,-32704; bl _s802874E0_0; lis 26,-32704; lwz 9,-16032(31); mr 24,3; lwz 10,0x8(27); addi 4,28,15672; rlwinm 11,9,2,0,29; addi 5,26,15724; stwx 30,11,10; addi 9,9,1; stw 9,-16032(31); li 6,138; lwz 9,0x8(30); lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,30,3; blrl; lwz 11,-16032(31); addi 4,28,15672; lwz 10,0x8(27); addi 5,26,15724; rlwinm 9,11,2,0,29; li 6,138; stwx 29,9,10; addi 11,11,1; stw 11,-16032(31); lwz 9,0x8(29); lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,29,3; blrl; lwz 4,-27536(13); mr 3,27; lwz 5,-27540(13); li 6,2; bl _s802874E0_1; lwz 9,-16032(31); lwz 0,0x8(27); rlwinm 9,9,2,0,29; add 9,9,0; lwz 3,-4(9); bl _s802874E0_2; lwz 9,-16032(31); mr 30,3; cmpwi 9,0; ble 1f; lwz 0,0x8(27); rlwinm 9,9,2,0,29; lis 4,-32704; addi 5,26,15724; add 9,9,0; addi 4,4,15876; lwz 11,-4(9); li 6,160; lwz 9,0x8(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,-16032(31); addi 9,9,-1; stw 9,-16032(31); 1:; mr 3,27; mr 4,24; mr 5,25; bl _s802874E0_3; mr 3,30; 2:; lwz 0,0x34(1); mtspr 8,0; lmw 24,0x10(1); addi 1,1,48"
extern "C" void _s802874E0_0();
extern "C" void _s802874E0_1();
extern "C" void _s802874E0_2();
extern "C" void _s802874E0_3();
extern "C" void f_802874E0() {}
