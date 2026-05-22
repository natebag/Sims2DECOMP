// 0x800CE300 NeighborhoodImpl::RemoveNeighborRelationships(Neighbor (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); addi 9,3,116; lwz 31,0x74(3); lwz 0,0x4(9); mr 28,4; lha 29,0x4(28); cmpw 31,0; beq 2f; mr 30,9; 0:; lwz 3,0x0(31); cmpwi 3,0; beq 1f; bl _s800CE300_0; lwz 9,0x0(3); mr 4,29; lha 0,0x30(9); lwz 9,0x34(9); add 3,3,0; mtspr 8,9; blrl; 1:; lwz 0,0x4(30); addi 31,31,4; cmpw 31,0; bne 0b; 2:; mr 3,28; bl _s800CE300_1; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800CE300_0();
extern "C" void _s800CE300_1();
extern "C" void f_800CE300() {}
