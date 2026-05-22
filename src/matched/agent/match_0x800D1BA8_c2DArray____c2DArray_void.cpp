// 0x800D1BA8 _c2DArray::~_c2DArray(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 3,0xc(31); cmpwi 3,0; beq 0f; lwz 9,-31944(13); mtspr 8,9; blrl; 0:; mr 3,31; bl _s800D1BA8_0; li 0,0; li 9,-1; stw 0,0x14(31); addi 3,31,16; stw 0,0xc(31); li 4,2; stw 9,0x8(31); stw 9,0x4(31); bl _s800D1BA8_1; andi. 0,30,1; beq 1f; mr 3,31; bl _s800D1BA8_2; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800D1BA8_0();
extern "C" void _s800D1BA8_1();
extern "C" void _s800D1BA8_2();
extern "C" void f_800D1BA8() {}
