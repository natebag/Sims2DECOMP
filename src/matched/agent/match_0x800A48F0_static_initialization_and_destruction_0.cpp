// 0x800A48F0 __static_initialization_and_destruction_0 (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 1f; cmpwi 3,0; beq 0f; lis 3,-32688; addi 3,3,-1792; bl _s800A48F0_0; lis 3,-32696; addi 3,3,23968; bl _s800A48F0_1; b 1f; 0:; lis 3,-32696; li 4,2; addi 3,3,23968; bl _s800A48F0_2; lis 3,-32688; li 4,2; addi 3,3,-1792; bl _s800A48F0_3; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800A48F0_0();
extern "C" void _s800A48F0_1();
extern "C" void _s800A48F0_2();
extern "C" void _s800A48F0_3();
extern "C" void f_800A48F0() {}
