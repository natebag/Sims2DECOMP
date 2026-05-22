// 0x80070B48 SimModel::Clone(void) (380 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 29,3; bl _s80070B48_0; cmpwi 3,0; li 3,0; bne 5f; li 3,360; addi 24,29,320; bl _s80070B48_1; addi 23,29,104; bl _s80070B48_2; mr 28,3; mr 9,29; mr 11,28; li 10,96; 0:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(9); li 5,104; li 4,0; addi 3,28,208; stw 0,0x0(11); addi 27,29,344; lwz 0,0x4(9); addi 25,28,104; addi 31,28,344; li 26,0; stw 0,0x4(11); li 30,4; bl _s80070B48_3; lwz 0,0x13c(29); mr 3,28; stw 0,0x13c(28); bl _s80070B48_4; li 3,16; bl _s80070B48_5; bl _s80070B48_6; stw 3,0x138(28); lwz 9,0x13c(29); lwz 4,0x84(9); bl _s80070B48_7; lwz 4,0x150(29); mr 3,28; bl _s80070B48_8; 1:; lwzx 0,26,24; cmpwi 0,0; beq 2f; mr 3,0; stw 0,-24(31); bl _s80070B48_9; 2:; lwz 4,0x0(27); mr 3,31; addi 27,27,4; addi 31,31,4; bl _s80070B48_10; addi 26,26,4; addic. 30,30,-1; bne 1b; mr 3,25; li 4,0; li 5,104; li 31,0; bl _s80070B48_11; li 30,26; 3:; lwzx 3,31,23; cmpwi 3,0; beq 4f; bl _s80070B48_12; stwx 3,31,25; 4:; addi 31,31,4; addic. 30,30,-1; bne 3b; mr 3,28; 5:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s80070B48_0();
extern "C" void _s80070B48_1();
extern "C" void _s80070B48_2();
extern "C" void _s80070B48_3();
extern "C" void _s80070B48_4();
extern "C" void _s80070B48_5();
extern "C" void _s80070B48_6();
extern "C" void _s80070B48_7();
extern "C" void _s80070B48_8();
extern "C" void _s80070B48_9();
extern "C" void _s80070B48_10();
extern "C" void _s80070B48_11();
extern "C" void _s80070B48_12();
extern "C" void f_80070B48() {}
