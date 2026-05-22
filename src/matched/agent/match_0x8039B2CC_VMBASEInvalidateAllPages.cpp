// 0x8039B2CC VMBASEInvalidateAllPages (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); bl _s8039B2CC_0; bl _s8039B2CC_1; bl _s8039B2CC_2; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8039B2CC_0();
extern "C" void _s8039B2CC_1();
extern "C" void _s8039B2CC_2();
extern "C" void f_8039B2CC() {}
