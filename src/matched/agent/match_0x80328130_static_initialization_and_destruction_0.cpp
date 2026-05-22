// 0x80328130 __static_initialization_and_destruction_0 (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 1f; cmpwi 3,0; beq 0f; lis 3,-32692; addi 3,3,-17464; bl _s80328130_0; b 1f; 0:; lis 3,-32692; li 4,2; addi 3,3,-17464; bl _s80328130_1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80328130_0();
extern "C" void _s80328130_1();
extern "C" void f_80328130() {}
