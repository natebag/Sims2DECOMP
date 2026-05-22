// 0x800A6D58 StringBuffer2::append(unsigned (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; mr 31,5; mr. 27,4; beq 7f; cmpwi 31,0; bge 0f; mr 3,27; bl _s800A6D58_0; mr 31,3; b 3f; 0:; li 9,0; cmpw 9,31; bge 2f; lhz 0,0x0(27); cmpwi 0,0; beq 2f; mr 11,27; 1:; addi 9,9,1; cmpw 9,31; bge 2f; lhzu 0,0x2(11); cmpwi 0,0; bne 1b; 2:; cmpw 31,9; ble 3f; mr 31,9; 3:; mr 3,28; bl _s800A6D58_1; mr 29,3; mr 3,28; add 30,31,29; bl _s800A6D58_2; cmpw 30,3; blt 4f; mr 3,28; bl _s800A6D58_3; subf 3,29,3; addi 31,3,-1; 4:; li 30,0; cmpw 30,31; bge 6f; mr 3,27; add 11,29,29; mr 30,31; 5:; lhz 0,0x0(3); addic. 30,30,-1; lwz 9,0x0(28); addi 3,3,2; sthx 0,11,9; addi 11,11,2; bne 5b; mr 30,31; 6:; mr 3,28; bl _s800A6D58_4; add 9,29,30; lwz 11,0x0(28); add 9,9,9; li 0,0; sthx 0,9,11; 7:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800A6D58_0();
extern "C" void _s800A6D58_1();
extern "C" void _s800A6D58_2();
extern "C" void _s800A6D58_3();
extern "C" void _s800A6D58_4();
extern "C" void f_800A6D58() {}
