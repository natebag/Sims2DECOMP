// 0x8019FA24 CASTattooTarget::RestoreClothesForTattoo(void) (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 29,3; addi 31,1,8; lwz 3,0x84(29); lwz 9,0x10(3); addi 30,9,300; bl _s8019FA24_0; mr 11,30; addi 9,29,140; li 10,288; 0:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(9); stw 0,0x0(11); lbz 0,0xf4(3); lhz 9,0xf2(3); stb 0,0xf4(30); sth 9,0xf2(30); lwz 29,0x84(29); mr 3,29; bl _s8019FA24_1; lis 30,-32698; lwz 9,0x84(3); addi 30,30,28648; li 0,1; stw 30,0x4(31); mr 3,29; stw 0,0x8(1); mr 4,31; stw 9,0x8(31); bl _s8019FA24_2; stw 30,0x4(31); mr 3,31; li 4,2; bl _s8019FA24_3; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s8019FA24_0();
extern "C" void _s8019FA24_1();
extern "C" void _s8019FA24_2();
extern "C" void _s8019FA24_3();
extern "C" void f_8019FA24() {}
