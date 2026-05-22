// 0x80131FE4 cXPortal::DumpRouteScores(ObjectModule (508 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); mr 31,3; mr 27,4; lis 3,-32706; lis 4,-32706; addi 3,3,-12332; addi 4,4,-12312; bl _s80131FE4_0; mr. 28,3; beq 10f; lis 4,-32706; mr 5,27; addi 4,4,-12308; mr 3,28; crxor 6,6,6; bl _s80131FE4_1; lwz 9,0x0(31); lha 3,0x98(9); lwz 0,0x9c(9); add 3,31,3; mtspr 8,0; blrl; mr. 29,3; beq 9f; addi 0,27,-1; rlwinm 25,27,0,16,31; rlwinm 26,0,2,0,29; 0:; lwz 9,0x4(29); lha 3,0x318(9); lwz 0,0x31c(9); add 3,29,3; mtspr 8,0; blrl; cmpwi 3,8; bne 8f; cmpwi 29,0; beq 1f; lwz 3,0x0(29); li 4,6; bl _s80131FE4_2; mr 31,3; b 2f; 1:; li 31,0; 2:; cmpwi 31,0; beq 3f; lwz 9,0x4(31); lha 3,0x20(9); lwz 0,0x24(9); add 3,31,3; mtspr 8,0; blrl; b 4f; 3:; li 3,0; 4:; cmpwi 27,0; ble 5f; lwz 9,0x8(3); lwz 0,0xc(3); subf 0,9,0; srawi 0,0,2; cmplw 25,0; bgt 5f; lfsx f13,9,26; b 6f; 5:; lis 9,-32706; lfs f13,-12248(9); 6:; lwz 9,0x0(31); fctiwz f0,f13; lwz 11,0x0(9); stfd f0,0x10(1); lwz 9,0x4(11); lwz 30,0x14(1); lwz 0,0x32c(9); lha 3,0x328(9); mtspr 8,0; add 3,11,3; blrl; mr 5,3; lis 4,-32706; mr 6,30; addi 4,4,-12284; mr 3,28; crxor 6,6,6; bl _s80131FE4_3; lwz 11,0x0(31); li 4,15; lwz 10,0x0(11); lwz 9,0x4(10); lha 3,0x1d0(9); lwz 0,0x1d4(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; bne 7f; lis 4,-32706; mr 3,28; addi 4,4,-12272; crxor 6,6,6; bl _s80131FE4_4; 7:; lis 4,-32706; mr 3,28; addi 4,4,-12256; crxor 6,6,6; bl _s80131FE4_5; 8:; lwz 9,0x4(29); lha 3,0x490(9); lwz 0,0x494(9); add 3,29,3; mtspr 8,0; blrl; mr. 29,3; bne 0b; 9:; lis 4,-32706; mr 3,28; addi 4,4,-12252; crxor 6,6,6; bl _s80131FE4_6; mr 3,28; bl _s80131FE4_7; 10:; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"
extern "C" void _s80131FE4_0();
extern "C" void _s80131FE4_1();
extern "C" void _s80131FE4_2();
extern "C" void _s80131FE4_3();
extern "C" void _s80131FE4_4();
extern "C" void _s80131FE4_5();
extern "C" void _s80131FE4_6();
extern "C" void _s80131FE4_7();
extern "C" void f_80131FE4() {}
