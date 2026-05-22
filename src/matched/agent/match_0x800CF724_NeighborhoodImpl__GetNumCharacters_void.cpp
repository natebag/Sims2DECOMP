// 0x800CF724 NeighborhoodImpl::GetNumCharacters(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); addi 9,3,116; lwz 31,0x74(3); lwz 0,0x4(9); li 30,0; cmpw 31,0; beq 2f; mr 29,9; 0:; lwz 3,0x0(31); cmpwi 3,0; beq 1f; bl _s800CF724_0; cmpwi 3,0; beq 1f; addi 30,30,1; 1:; lwz 0,0x4(29); addi 31,31,4; cmpw 31,0; bne 0b; 2:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800CF724_0();
extern "C" void f_800CF724() {}
