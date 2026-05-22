// 0x8003ECA8 EGlobal::LoadPreGlobalRequirements(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; addi 0,30,360; li 3,268; stw 0,-21436(13); bl _s8003ECA8_0; bl _s8003ECA8_1; mr 0,3; mr 4,30; stw 0,0x114(30); bl _s8003ECA8_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8003ECA8_0();
extern "C" void _s8003ECA8_1();
extern "C" void _s8003ECA8_2();
extern "C" void f_8003ECA8() {}
