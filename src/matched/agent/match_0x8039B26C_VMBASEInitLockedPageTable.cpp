// 0x8039B26C __VMBASEInitLockedPageTable (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); bl _s8039B26C_0; stw 3,-21528(13); addi 3,3,4096; bl _s8039B26C_1; bl _s8039B26C_2; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8039B26C_0();
extern "C" void _s8039B26C_1();
extern "C" void _s8039B26C_2();
extern "C" void f_8039B26C() {}
