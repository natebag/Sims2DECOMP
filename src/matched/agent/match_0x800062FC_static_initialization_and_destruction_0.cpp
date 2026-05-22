// 0x800062FC __static_initialization_and_destruction_0 (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 2f; cmpwi 3,0; beq 1f; lis 9,-32697; li 0,0; addi 9,9,-7712; li 10,0; stw 0,0x18(9); addi 11,9,38; stw 0,0x14(9); li 0,6; mtspr 9,0; 0:; sth 10,0x0(11); addi 11,11,-2; bdnz 0b; lis 3,-32697; addi 3,3,-7672; bl _s800062FC_0; b 2f; 1:; lis 3,-32697; li 4,2; addi 3,3,-7672; bl _s800062FC_1; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800062FC_0();
extern "C" void _s800062FC_1();
extern "C" void f_800062FC() {}
