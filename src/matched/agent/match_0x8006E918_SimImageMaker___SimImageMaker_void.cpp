// 0x8006E918 SimImageMaker::~SimImageMaker(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s8006E918_0; addi 3,31,16; li 4,2; bl _s8006E918_1; andi. 0,30,1; beq 0f; mr 3,31; bl _s8006E918_2; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8006E918_0();
extern "C" void _s8006E918_1();
extern "C" void _s8006E918_2();
extern "C" void f_8006E918() {}
