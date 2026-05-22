// 0x8039257C VMInvalidateAllPages (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); bl _s8039257C_0; li 3,1; bl _s8039257C_1; li 3,0; bl _s8039257C_2; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8039257C_0();
extern "C" void _s8039257C_1();
extern "C" void _s8039257C_2();
extern "C" void f_8039257C() {}
