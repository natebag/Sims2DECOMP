// 0x8034A488 __static_initialization_and_destruction_0 (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 1f; cmpwi 3,0; beq 0f; lis 3,-32691; addi 3,3,21688; bl _s8034A488_0; lwz 0,-18444(13); lis 3,-32690; addi 3,3,-25824; stw 0,-22500(13); bl _s8034A488_1; lis 3,-32690; addi 3,3,-25796; bl _s8034A488_2; b 1f; 0:; lis 3,-32690; li 4,2; addi 3,3,-25796; bl _s8034A488_3; lis 3,-32690; li 4,2; addi 3,3,-25824; bl _s8034A488_4; lis 3,-32691; li 4,2; addi 3,3,21688; bl _s8034A488_5; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8034A488_0();
extern "C" void _s8034A488_1();
extern "C" void _s8034A488_2();
extern "C" void _s8034A488_3();
extern "C" void _s8034A488_4();
extern "C" void _s8034A488_5();
extern "C" void f_8034A488() {}
