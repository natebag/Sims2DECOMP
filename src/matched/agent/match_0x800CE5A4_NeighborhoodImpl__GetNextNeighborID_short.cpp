// 0x800CE5A4 NeighborhoodImpl::GetNextNeighborID(short) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x74(3); lwz 0,0x78(3); subf 0,9,0; srawi 0,0,2; cmplw 4,0; bge 2f; mr 10,9; mr 11,0; 0:; addi 0,4,1; extsh 4,0; addi 9,4,-1; rlwinm 9,9,2,0,29; lwzx 0,10,9; cmpwi 0,0; beq 1f; mr 3,4; blr; 1:; cmplw 4,11; blt 0b; 2:; li 3,0"
extern "C" int f_800CE5A4() {}
