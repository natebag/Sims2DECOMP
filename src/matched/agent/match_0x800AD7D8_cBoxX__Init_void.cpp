// 0x800AD7D8 cBoxX::Init(void) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; lis 4,3123; lis 3,-32692; li 5,0; li 6,0; ori 4,4,56129; addi 3,3,-20832; li 29,1; bl _s800AD7D8_0; li 28,0; stw 3,0x68(30); li 3,4224; bl _s800AD7D8_1; bl _s800AD7D8_2; mr 0,3; stw 0,-24136(13); bl _s800AD7D8_3; mr 3,30; bl _s800AD7D8_4; lwz 3,-24136(13); lis 4,-32757; addi 4,4,-10712; bl _s800AD7D8_5; li 3,60; bl _s800AD7D8_6; li 4,0; bl _s800AD7D8_7; stw 3,0x64(30); li 3,8; bl _s800AD7D8_8; mr 9,3; stw 9,0x10(30); stw 28,0x4(9); stw 29,0x0(9); bl _s800AD7D8_9; stw 28,0x14(30); li 3,1; stw 29,0x4(30); stw 29,-32088(13); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800AD7D8_0();
extern "C" void _s800AD7D8_1();
extern "C" void _s800AD7D8_2();
extern "C" void _s800AD7D8_3();
extern "C" void _s800AD7D8_4();
extern "C" void _s800AD7D8_5();
extern "C" void _s800AD7D8_6();
extern "C" void _s800AD7D8_7();
extern "C" void _s800AD7D8_8();
extern "C" void _s800AD7D8_9();
extern "C" void f_800AD7D8() {}
