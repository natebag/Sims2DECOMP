// 0x80329EBC Emboss2(short (360 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 24,0x40(1); stw 0,0x64(1); mr 28,6; mr 25,5; mullw 31,25,28; mr 24,4; mr 27,7; addi 26,1,56; mr 29,3; bl _s80329EBC_0; rlwinm 4,31,1,0,30; li 5,0; bl _s80329EBC_1; mr 30,3; addi 6,1,16; cmpwi 31,0; ble 1f; mtspr 9,31; lis 7,21845; ori 7,7,21846; li 8,0; 0:; lhax 11,8,29; rlwinm 9,11,27,27,31; rlwinm 0,11,22,27,31; add 0,0,9; rlwinm 11,11,0,27,31; add 0,0,11; mulhw 10,0,7; srawi 0,0,31; subf 10,0,10; rlwinm 9,10,10,0,21; rlwinm 0,10,5,0,26; or 9,9,0; or 9,9,10; sthx 9,8,30; addi 8,8,2; bdnz 0b; 1:; lis 9,-32702; mr 11,6; addi 9,9,4800; li 10,24; 2:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 2b; lwz 0,0x0(9); addi 3,1,16; li 4,9; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); bl _s80329EBC_2; lhz 0,0x0(27); mr 8,3; lbz 11,0x2(27); mr 4,24; sth 0,0x38(1); mr 6,28; stw 26,0x8(1); addi 7,1,16; li 9,3; li 10,3; mr 5,25; stb 11,0x2(26); mr 3,30; bl _s80329EBC_3; bl _s80329EBC_4; mr 4,30; bl _s80329EBC_5; lwz 0,0x64(1); mtspr 8,0; lmw 24,0x40(1); addi 1,1,96"
extern "C" void _s80329EBC_0();
extern "C" void _s80329EBC_1();
extern "C" void _s80329EBC_2();
extern "C" void _s80329EBC_3();
extern "C" void _s80329EBC_4();
extern "C" void _s80329EBC_5();
extern "C" void f_80329EBC() {}
