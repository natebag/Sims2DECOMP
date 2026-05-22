// 0x80189444 HUDTarget::ApplyMotiveCurveArray(unsigned (360 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 25,3; mr 23,4; lhz 0,0xca(25); mr 24,5; cmpwi 0,0; bne 0f; li 3,0; b 9f; 0:; lwz 31,0xa0(25); cmpwi 31,0; beq 4f; lwz 9,0x0(31); cmpwi 9,0; beq 3f; lwz 0,-8(9); mulli 0,0,20; add 30,9,0; cmpw 9,30; beq 2f; 1:; addi 30,30,-20; li 4,0; mr 3,30; bl _s80189444_0; lwz 0,0x0(31); cmpw 0,30; bne 1b; 2:; lwz 3,0x0(31); addi 3,3,-8; bl _s80189444_1; 3:; li 30,0; mr 3,31; stw 30,0x0(31); bl _s80189444_2; stw 30,0xa0(25); 4:; li 3,8; bl _s80189444_3; lhz 30,0xca(25); mr 29,3; li 0,0; addi 27,30,2; stw 0,0x0(29); mulli 3,27,20; stw 27,0x4(29); addi 31,30,1; addi 3,3,8; bl _s80189444_4; addi 28,3,8; cmpwi 30,-2; stw 27,-8(28); mr 30,28; beq 6f; li 26,-1; 5:; mr 3,30; bl _s80189444_5; stw 26,0x10(30); cmpwi 31,0; addi 30,30,20; addi 31,31,-1; bne 5b; 6:; li 31,0; stw 28,0x0(29); cmpw 31,27; bge 8f; li 30,0; 7:; lwz 3,0x0(29); li 4,8; add 3,3,30; bl _s80189444_6; lwz 9,0x0(29); add 9,30,9; stw 31,0x10(9); addi 30,30,20; addi 31,31,1; cmpw 31,27; blt 7b; 8:; stw 29,0xa0(25); mr 3,29; mr 4,23; mr 5,24; bl _s80189444_7; li 3,1; 9:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s80189444_0();
extern "C" void _s80189444_1();
extern "C" void _s80189444_2();
extern "C" void _s80189444_3();
extern "C" void _s80189444_4();
extern "C" void _s80189444_5();
extern "C" void _s80189444_6();
extern "C" void _s80189444_7();
extern "C" void f_80189444() {}
