// 0x8019F8D8 CASTattooTarget::RemoveClothesForTattoo(void) (332 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 29,3; addi 28,1,8; lwz 3,0x84(29); li 30,288; bl _s8019F8D8_0; mr 31,3; addi 11,29,140; mr 9,31; 0:; lwz 0,0x0(9); addic. 30,30,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(9); mr 3,31; li 4,1; stw 0,0x0(11); bl _s8019F8D8_1; lwz 8,0x84(31); cmpwi 8,0; beq 1f; li 0,3; li 9,3; li 11,8; li 10,9; stb 0,0x98(31); stb 30,0x99(31); stw 9,0xa0(31); b 2f; 1:; li 0,8; li 9,2; li 11,7; li 10,4; stb 0,0x98(31); stb 9,0x99(31); stw 8,0xa0(31); 2:; stb 11,0xc4(31); stb 10,0xcc(31); li 11,0; lis 30,-32698; stw 11,0x9c(31); addi 30,30,25128; stb 11,0xc5(31); li 10,6; stw 11,0xc8(31); mr 4,28; stb 11,0xcd(31); stw 11,0xd0(31); lbz 0,0x119(29); stb 0,0x8d(31); lwz 9,0x11c(29); stw 9,0x90(31); lbz 0,0x11a(29); stb 0,0x8e(31); stw 30,0x4(28); lwz 3,0x84(29); stw 10,0x8(1); stw 11,0x8(28); bl _s8019F8D8_2; stw 30,0x4(28); mr 3,28; li 4,2; bl _s8019F8D8_3; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s8019F8D8_0();
extern "C" void _s8019F8D8_1();
extern "C" void _s8019F8D8_2();
extern "C" void _s8019F8D8_3();
extern "C" void f_8019F8D8() {}
