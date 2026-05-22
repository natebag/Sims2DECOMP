// 0x8025C53C stateError (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s8025C53C_0; lis 3,-32730; addi 3,3,-15216; bl _s8025C53C_1; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8025C53C_0();
extern "C" void _s8025C53C_1();
extern "C" void f_8025C53C() {}
