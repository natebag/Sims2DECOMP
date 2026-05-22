// 0x803841C8 ReadCallback (304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stmw 27,0x14(1); addi 29,3,0; lis 3,-32688; mulli 5,29,272; addi 0,3,-24000; mr. 30,4; add 31,0,5; blt 5f; lwz 28,0xc0(31); lwz 4,0xc(28); cmpwi 4,0; bge 0f; li 30,-14; b 5f; 0:; lwz 5,0xc(31); lwz 6,0x8(28); addi 0,5,-1; not 3,0; add 0,6,5; and 0,3,0; subf 27,6,0; subf 0,27,4; stw 0,0xc(28); lwz 0,0xc(28); cmpwi 0,0; ble 5f; mr 3,31; bl _s803841C8_0; lwz 0,0x8(28); add 0,0,27; stw 0,0x8(28); lhz 0,0x10(28); rlwinm 0,0,1,0,30; lhzx 0,3,0; sth 0,0x10(28); lhz 3,0x10(28); cmplwi 3,5; blt 1f; lhz 0,0x10(31); cmplw 3,0; blt 2f; 1:; li 30,-6; b 5f; 2:; lwz 5,0xc(28); lwz 0,0xc(31); cmpw 5,0; bge 3f; b 4f; 3:; mr 5,0; 4:; mullw 4,0,3; lwz 6,0xb4(31); lis 3,-32712; addi 7,3,16840; addi 3,29,0; bl _s803841C8_1; mr. 30,3; bge 6f; 5:; lwz 27,0xd0(31); li 0,0; addi 3,31,0; stw 0,0xd0(31); mr 4,30; bl _s803841C8_2; addi 12,27,0; mtspr 8,12; addi 3,29,0; addi 4,30,0; blrl; 6:; lmw 27,0x14(1); lwz 0,0x2c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s803841C8_0();
extern "C" void _s803841C8_1();
extern "C" void _s803841C8_2();
extern "C" void f_803841C8() {}
