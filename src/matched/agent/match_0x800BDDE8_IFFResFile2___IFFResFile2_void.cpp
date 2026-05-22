// 0x800BDDE8 IFFResFile2::~IFFResFile2(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; lis 11,-32698; mr 31,3; addi 9,9,-2600; addi 11,11,-2576; mr 30,4; stw 9,0x134(31); stw 11,0xc(31); bl _s800BDDE8_0; cmpwi 3,0; beq 0f; mr 3,31; bl _s800BDDE8_1; 0:; addi 3,31,16; li 4,0; bl _s800BDDE8_2; mr 3,31; mr 4,30; bl _s800BDDE8_3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800BDDE8_0();
extern "C" void _s800BDDE8_1();
extern "C" void _s800BDDE8_2();
extern "C" void _s800BDDE8_3();
extern "C" void f_800BDDE8() {}
