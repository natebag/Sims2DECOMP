// 0x800A6620 StringBuffer::append(char (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; mr 31,5; mr. 27,4; beq 7f; cmpwi 31,0; bge 0f; mr 3,27; bl _s800A6620_0; mr 31,3; b 3f; 0:; li 9,0; cmpw 9,31; bge 2f; lbz 0,0x0(27); cmpwi 0,0; beq 2f; 1:; addi 9,9,1; cmpw 9,31; bge 2f; lbzx 0,27,9; cmpwi 0,0; bne 1b; 2:; cmpw 31,9; ble 3f; mr 31,9; 3:; mr 3,28; bl _s800A6620_1; mr 29,3; mr 3,28; add 30,31,29; bl _s800A6620_2; cmpw 30,3; blt 4f; mr 3,28; bl _s800A6620_3; subf 3,29,3; addi 31,3,-1; 4:; li 30,0; cmpw 30,31; bge 6f; 5:; add 11,29,30; lbzx 0,27,30; lwz 9,0x0(28); addi 30,30,1; cmpw 30,31; stbx 0,9,11; blt 5b; 6:; mr 3,28; bl _s800A6620_4; lwz 11,0x0(28); add 9,29,30; li 0,0; stbx 0,11,9; 7:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800A6620_0();
extern "C" void _s800A6620_1();
extern "C" void _s800A6620_2();
extern "C" void _s800A6620_3();
extern "C" void _s800A6620_4();
extern "C" void f_800A6620() {}
