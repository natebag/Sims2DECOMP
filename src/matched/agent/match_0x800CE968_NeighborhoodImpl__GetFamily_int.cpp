// 0x800CE968 NeighborhoodImpl::GetFamily(int) (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; mr 30,4; addi 9,29,92; lwz 31,0x5c(29); lwz 0,0x4(9); cmpw 31,0; beq 1f; mr 28,9; 0:; lwz 3,0x0(31); lwz 9,0x0(3); lha 0,0x98(9); lwz 9,0x9c(9); add 3,3,0; mtspr 8,9; blrl; cmpw 3,30; beq 2f; lwz 0,0x4(28); addi 31,31,4; cmpw 31,0; bne 0b; 1:; cmpwi 30,1; bne 3f; lis 9,-32697; lwz 0,0x5c6c(9); cmpwi 0,0; beq 3f; lwz 9,0x0(29); lwz 4,0x70(29); lha 3,0x128(9); lwz 0,0x12c(9); add 3,29,3; mtspr 8,0; blrl; b 4f; 2:; lwz 3,0x0(31); b 4f; 3:; li 3,0; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void f_800CE968() {}
