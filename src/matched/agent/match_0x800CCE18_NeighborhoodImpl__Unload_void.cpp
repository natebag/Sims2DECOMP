// 0x800CCE18 NeighborhoodImpl::Unload(void) (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 27,0x2c(1); stw 0,0x44(1); mr 30,3; addi 29,1,8; addi 3,30,116; addi 27,1,32; bl _s800CCE18_0; lwz 11,-21508(13); lwz 9,0x0(11); lwz 0,0x4c(9); lha 3,0x48(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21508(13); lwz 9,0x0(11); lwz 0,0x54(9); lha 3,0x50(9); mtspr 8,0; add 3,11,3; blrl; addi 9,30,92; lwz 31,0x5c(30); lwz 0,0x4(9); cmpw 31,0; beq 1f; mr 28,9; 0:; lwz 3,0x0(31); addi 31,31,4; bl _s800CCE18_1; lwz 0,0x4(28); cmpw 31,0; bne 0b; 1:; li 0,0; addi 8,29,8; stw 0,0x8(1); addi 7,30,100; stw 0,0x4(29); stw 0,0x4(8); lwz 0,0x60(30); lwz 9,0x5c(30); lwz 11,0x8(1); lwz 10,0xc(1); stw 9,0x8(1); stw 0,0xc(1); stw 11,0x5c(30); lwz 0,0x4(8); stw 10,0x60(30); stw 0,0x4(27); lwz 9,0x64(30); lwz 0,0x4(7); stw 9,0x8(29); stw 0,0x4(8); lwz 9,0x20(1); lwz 0,0x24(1); stw 9,0x64(30); stw 0,0x4(7); lwz 3,0x8(1); cmpwi 3,0; beq 3f; lwz 0,0xc(29); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 2f; bl _s800CCE18_2; b 3f; 2:; bl _s800CCE18_3; 3:; lwz 0,0x44(1); mtspr 8,0; lmw 27,0x2c(1); addi 1,1,64"
extern "C" void _s800CCE18_0();
extern "C" void _s800CCE18_1();
extern "C" void _s800CCE18_2();
extern "C" void _s800CCE18_3();
extern "C" void f_800CCE18() {}
