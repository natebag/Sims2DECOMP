// 0x803C989C __eh_rtime_match (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32693; li 5,8; addi 3,3,11064; bl _s803C989C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 4,4; beq 0f; lis 3,-32693; addi 3,3,11064; bl _s803C989C_1; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; li 0,0; stw 0,0x4(3); stw 0,0x0(3); stw 0,0x8(3)"
extern "C" void _s803C989C_0();
extern "C" void _s803C989C_1();
extern "C" void f_803C989C() {}
