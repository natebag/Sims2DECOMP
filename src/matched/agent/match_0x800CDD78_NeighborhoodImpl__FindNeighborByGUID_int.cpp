// 0x800CDD78 NeighborhoodImpl::FindNeighborByGUID(int) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr. 28,4; bne 0f; li 3,0; b 4f; 0:; addi 9,3,116; lwz 31,0x74(3); lwz 0,0x4(9); mr 29,9; li 30,0; cmpw 31,0; beq 3f; 1:; lwz 3,0x0(31); cmpwi 3,0; beq 2f; bl _s800CDD78_0; cmpw 3,28; bne 2f; cmpwi 30,0; bne 2f; lwz 30,0x0(31); 2:; lwz 0,0x4(29); addi 31,31,4; cmpw 31,0; bne 1b; 3:; mr 3,30; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800CDD78_0();
extern "C" void f_800CDD78() {}
