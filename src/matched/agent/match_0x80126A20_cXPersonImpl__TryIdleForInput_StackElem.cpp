// 0x80126A20 cXPersonImpl::TryIdleForInput(StackElem (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,4; lwz 3,0x4(30); mr 31,5; lwz 9,0x4(3); lha 0,0x2e0(9); lwz 9,0x2e4(9); add 3,3,0; mtspr 8,9; blrl; mr 28,3; lha 9,0x0(31); cmpwi 9,0; blt 0f; lbz 0,0x7(29); cmpw 9,0; blt 1f; 0:; lwz 9,0x0(30); li 0,1; stw 0,-24512(13); li 10,8; lwz 11,0x0(9); li 4,8; sth 10,0x34(11); lwz 9,0x0(30); lwz 10,0x4(9); lwz 11,0x4(10); lha 3,0x110(11); lwz 0,0x114(11); add 3,10,3; mtspr 8,0; blrl; li 3,-1; li 4,-1; b 5f; 1:; mr 3,29; bl _s80126A20_0; lha 0,0x0(31); mr 10,3; cmpwi 28,0; add 9,0,0; add 5,10,9; bne 3f; lhzx 11,10,9; cmpwi 11,0; bne 2f; lwz 30,0x0(30); li 4,8; addi 30,30,40; mr 3,30; bl _s80126A20_1; lha 5,0x0(3); li 4,8; mr 3,30; rlwinm 5,5,0,26,24; bl _s80126A20_2; li 3,0; li 4,1; b 5f; 2:; addi 0,11,-1; li 3,0; li 4,2; sthx 0,10,9; b 5f; 3:; lha 0,0x2(31); li 6,1; cmpwi 0,0; bne 4f; li 6,0; 4:; mr 3,30; mr 4,29; bl _s80126A20_3; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80126A20_0();
extern "C" void _s80126A20_1();
extern "C" void _s80126A20_2();
extern "C" void _s80126A20_3();
extern "C" void f_80126A20() {}
