// 0x800CDEE0 NeighborhoodImpl::FindNeighborByType(ObjSelector (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x78(3); li 10,0; lwz 11,0x74(3); cmpw 11,0; beq 2f; mr 8,0; 0:; lwz 9,0x0(11); cmpwi 9,0; beq 1f; lwz 0,0xc(9); cmpw 0,4; bne 1f; cmpwi 10,0; bne 1f; mr 10,9; 1:; addi 11,11,4; cmpw 11,8; bne 0b; 2:; mr 3,10"
extern "C" int f_800CDEE0() {}
