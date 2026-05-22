// 0x800A13F4 BString2::compare_str(unsigned (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 29,4; mr 28,5; mr 31,6; mr 27,7; bl _s800A13F4_0; cmplw 29,3; ble 0f; bl _s800A13F4_1; 0:; cmplw 31,27; ble 1f; mr 31,27; 1:; mr 3,30; bl _s800A13F4_2; cmpwi 3,0; bne 3f; cmpwi 28,0; beq 2f; bl _s800A13F4_3; lhz 0,0x0(28); subf 3,0,3; b 6f; 2:; bl _s800A13F4_4; b 6f; 3:; mr 3,30; bl _s800A13F4_5; cmpwi 3,0; beq 4f; lwz 9,0x0(30); lwz 9,0x0(9); b 5f; 4:; li 9,0; 5:; add 3,29,29; mr 4,28; add 3,3,9; rlwinm 5,31,1,0,30; bl _s800A13F4_6; mr. 3,3; bne 6f; mr 3,30; bl _s800A13F4_7; subf 3,29,3; subf 3,27,3; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800A13F4_0();
extern "C" void _s800A13F4_1();
extern "C" void _s800A13F4_2();
extern "C" void _s800A13F4_3();
extern "C" void _s800A13F4_4();
extern "C" void _s800A13F4_5();
extern "C" void _s800A13F4_6();
extern "C" void _s800A13F4_7();
extern "C" void f_800A13F4() {}
