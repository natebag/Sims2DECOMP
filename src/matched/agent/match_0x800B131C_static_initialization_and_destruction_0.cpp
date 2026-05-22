// 0x800B131C __static_initialization_and_destruction_0 (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 1f; cmpwi 3,0; beq 0f; lis 3,-32696; addi 3,3,24032; bl _s800B131C_0; b 1f; 0:; lis 9,-32696; lis 11,-32697; addi 30,9,24032; addi 11,11,-24248; addi 3,30,28; li 4,2; stw 11,0x5de0(9); bl _s800B131C_1; mr 3,30; li 4,2; bl _s800B131C_2; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800B131C_0();
extern "C" void _s800B131C_1();
extern "C" void _s800B131C_2();
extern "C" void f_800B131C() {}
