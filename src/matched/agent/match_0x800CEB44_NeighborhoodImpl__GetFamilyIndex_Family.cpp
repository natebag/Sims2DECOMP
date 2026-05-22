// 0x800CEB44 NeighborhoodImpl::GetFamilyIndex(Family (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 28,4; addi 11,30,92; lwz 9,0x5c(30); lwz 0,0x4(11); li 31,0; subf 0,9,0; rlwinm. 9,0,30,2,31; beq 2f; mr 29,11; 0:; lwz 9,0x0(30); mr 4,31; lha 3,0x118(9); lwz 0,0x11c(9); add 3,30,3; mtspr 8,0; blrl; cmpw 3,28; bne 1f; mr 3,31; b 3f; 1:; lwz 9,0x4(29); addi 31,31,1; lwz 0,0x5c(30); subf 9,0,9; srawi 9,9,2; cmplw 31,9; blt 0b; 2:; li 3,-1; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void f_800CEB44() {}
