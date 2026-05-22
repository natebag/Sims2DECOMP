// 0x801253E4 cXPersonImpl::SimMotives(void) (364 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f31,0x38(1); stmw 22,0x10(1); stw 0,0x44(1); mr 28,3; lis 9,-32706; addi 26,28,168; lfs f31,-12992(9); mr 24,26; addi 25,28,232; li 31,0; addi 27,1,8; li 22,0; li 23,-8261; 0:; rlwinm 0,31,2,0,29; lfsx f0,26,0; fcmpu 0,f0,f31; cror 3,2,1; bns 1f; lfsx f0,25,0; fcmpu 0,f0,f31; bge 1f; lwz 10,0x4(28); lwz 30,-21476(13); lwz 9,0x4(10); lwz 11,0x0(30); lha 3,0x1b0(9); lwz 9,0x1b4(9); addi 29,11,184; add 3,10,3; lha 0,0xb8(11); mtspr 8,9; add 30,30,0; blrl; lwz 0,0x4(29); mr 4,3; mr 3,30; mtspr 8,0; blrl; lhz 0,-21224(13); mr 4,27; sth 22,0x8(1); li 5,1; sth 0,0x4(27); sth 0,0x2(27); sth 23,0x8(1); sth 31,0xa(1); bl _s801253E4_0; 1:; addi 0,31,1; extsh 31,0; cmpwi 31,15; ble 0b; lwz 3,0x0(28); li 4,34; addi 3,3,40; bl _s801253E4_1; lha 0,0x0(3); cmpwi 0,0; bne 3f; lwz 9,0x0(28); lwz 10,0x4(9); lwz 11,0x4(10); lha 3,0x1a8(11); lwz 0,0x1ac(11); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; beq 3f; lha 0,0x42(28); cmpwi 0,0; beq 2f; mr 3,24; bl _s801253E4_2; lwz 3,0x4(28); lwz 9,0x4(3); lha 0,0x80(9); lwz 9,0x84(9); add 3,3,0; mtspr 8,9; blrl; b 3f; 2:; mr 3,24; bl _s801253E4_3; 3:; lwz 0,0x44(1); mtspr 8,0; lmw 22,0x10(1); lfd f31,0x38(1); addi 1,1,64"
extern "C" void _s801253E4_0();
extern "C" void _s801253E4_1();
extern "C" void _s801253E4_2();
extern "C" void _s801253E4_3();
extern "C" void f_801253E4() {}
