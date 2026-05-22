// 0x8003E560 EGlobal::CreateAnimator(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); bl _s8003E560_0; li 6,0; li 7,0; li 4,1648; li 5,16; bl _s8003E560_1; mr 30,3; li 4,0; li 5,1648; bl _s8003E560_2; mr 3,30; bl _s8003E560_3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8003E560_0();
extern "C" void _s8003E560_1();
extern "C" void _s8003E560_2();
extern "C" void _s8003E560_3();
extern "C" void f_8003E560() {}
