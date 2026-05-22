// 0x800477A0 EFloorShdTblNode::RemapFloorAndGrassId(unsigned (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 3,3; beq 0f; bl _s800477A0_0; b 1f; 0:; lwz 3,-32492(13); 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800477A0_0();
extern "C" void f_800477A0() {}
