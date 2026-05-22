// 0x80116A14 cHitMan::~cHitMan(void) (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 28,4; lwz 3,0x50(31); cmpwi 3,0; beq 0f; li 4,3; bl _s80116A14_0; 0:; li 29,0; addi 30,31,64; stw 29,0x50(31); lwz 0,0x8(30); cmpwi 0,0; beq 1f; lwz 9,0x4(30); mr 3,30; lwz 4,0x4(9); bl _s80116A14_1; lwz 9,0x4(30); stw 9,0x8(9); lwz 11,0x4(30); stw 29,0x4(11); lwz 9,0x4(30); stw 9,0xc(9); stw 29,0x8(30); 1:; lwz 3,0x4(30); cmpwi 3,0; beq 2f; li 4,24; bl _s80116A14_2; 2:; addi 30,31,52; mr 3,30; bl _s80116A14_3; lwz 3,0x4(30); cmpwi 3,0; beq 3f; li 4,12; bl _s80116A14_4; 3:; addi 30,31,32; lwz 0,0x8(30); cmpwi 0,0; beq 4f; lwz 9,0x4(30); mr 3,30; lwz 4,0x4(9); bl _s80116A14_5; lwz 9,0x4(30); stw 9,0x8(9); lwz 11,0x4(30); stw 29,0x4(11); lwz 9,0x4(30); stw 9,0xc(9); stw 29,0x8(30); 4:; lwz 3,0x4(30); cmpwi 3,0; beq 5f; li 4,24; bl _s80116A14_6; 5:; addi 30,31,4; mr 3,30; bl _s80116A14_7; lwz 3,0x4(30); cmpwi 3,0; beq 6f; li 4,12; bl _s80116A14_8; 6:; andi. 0,28,1; beq 7f; mr 3,31; bl _s80116A14_9; 7:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80116A14_0();
extern "C" void _s80116A14_1();
extern "C" void _s80116A14_2();
extern "C" void _s80116A14_3();
extern "C" void _s80116A14_4();
extern "C" void _s80116A14_5();
extern "C" void _s80116A14_6();
extern "C" void _s80116A14_7();
extern "C" void _s80116A14_8();
extern "C" void _s80116A14_9();
extern "C" void f_80116A14() {}
