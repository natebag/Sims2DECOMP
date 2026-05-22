// 0x800D1B1C _c2DArray::_c2DArray(int, (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,3; mr 26,6; mr 28,7; mr 27,5; mr 29,4; addi 3,30,16; bl _s800D1B1C_0; li 9,-1; li 0,0; stw 29,0x14(30); mr 3,30; stw 9,0x8(30); stw 0,0xc(30); stw 9,0x4(30); bl _s800D1B1C_1; mr 4,28; mr 3,30; bl _s800D1B1C_2; mr 5,26; mr 4,27; mr 3,30; bl _s800D1B1C_3; mr 3,30; li 4,0; bl _s800D1B1C_4; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s800D1B1C_0();
extern "C" void _s800D1B1C_1();
extern "C" void _s800D1B1C_2();
extern "C" void _s800D1B1C_3();
extern "C" void _s800D1B1C_4();
extern "C" void f_800D1B1C() {}
