// 0x800F8444 ObjectModuleImpl::UpdateWallAdjacencies(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 31,0x2c(3); cmpwi 31,0; beq 3f; 0:; lwz 11,0x4(31); lwz 9,0x4(11); lwz 0,0x1cc(9); lha 3,0x1c8(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); li 4,6; lha 0,0x70(9); lwz 9,0x74(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; li 0,1; bne 1f; li 0,0; 1:; cmpwi 0,0; beq 2f; mr 3,31; bl _s800F8444_0; 2:; lwz 31,0x5c(31); cmpwi 31,0; bne 0b; 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800F8444_0();
extern "C" void f_800F8444() {}
