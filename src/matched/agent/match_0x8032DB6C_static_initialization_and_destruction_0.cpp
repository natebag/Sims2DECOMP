// 0x8032DB6C __static_initialization_and_destruction_0 (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 1f; cmpwi 3,0; beq 0f; addi 3,13,-22568; bl _s8032DB6C_0; b 1f; 0:; addi 3,13,-22568; li 4,2; bl _s8032DB6C_1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8032DB6C_0();
extern "C" void _s8032DB6C_1();
extern "C" void f_8032DB6C() {}
